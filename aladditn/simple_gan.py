import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
import torchvision.datasets as datasets
from torch.utils.data import DataLoader
import torchvision.transforms as transforms
from torch.utils.tensorboard import SummaryWriter


class Descriminator(nn.Module):
    def __init__(self, img_dim):
        super().__init__()
        self.disc = nn.Sequential(
            nn.Linear(img_dim, 256),
            nn.LeakyReLU(0.1),#in Gan leaky relu works better than relu
            nn.Linear(256,1)
        )

    def forward(self, x):
        return self.disc(x)


class Generator(nn.Module):
    def __init__(self,z_dim, img_dim):
        self.gen = nn.Sequential(
            nn.Linear(z_dim,256),
            nn.LeakyReLU(0.1),
            nn.Linear(256,img_dim),
            nn.Tanh()# since we have normalized mnist data in between -1 and 1 it is essential to use activation function that works as per normalization
        )

    def forward(self, x):
        return self.gen(x)


#Hyperparameters etc.

device = "cuda" if torch.cuda.is_available() else "cpu"
lr = 3e-4
z_dim = 64
img_dim = 28*28*1
batch_size = 32
num_epochs = 50

disc = Descriminator(img_dim).to(device)
gen = Generator(z_dim,img_dim).to(device)
fixed_noise = torch.randn((batch_size,z_dim)).to(device)
transforms = transforms.Compose(
    [transforms.ToTensor(), transforms.Normalize((0.1307,), (0.3081,))]
)

dataset = datasets.MNIST(root="dataset/",transforms=transforms,download=True)
loader = DataLoader(dataset, batch_size=batch_size, shuffle=True)
opt_disc = optim.Adam(disc.parameters(),lr=lr)
opt_gen = optim.Adam(gen.parameters(),lr=lr)
criterion = nn.BCELoss()
writer_fake = SummaryWriter(F"rund/GAN_MNIST/FAKE")
writer_real = SummaryWriter(F"rund/GAN_MNIST/REAL")

step=0


for epoch in range(num_epochs):
    for batch_idx, (real, _) in enumerate(loader):
        real = real.view(-1, 784) #we keep no of example in size so we used -1
        batch_size = real.shape[0]

        ###
        noise = torch.randn(batch_size, z_dim).to(device)
        fake = gen(noise)
        disc_real = disc(real).view(-1)
        lossD_real = criterion(disc_real, torch.ones_like(disc_real))
        disc_fake = disc(fake.detach()).view(-1)
        lossD_fake = criterion(disc_fake, torch.zeros_like(disc_fake))
        lossD = (lossD_real + lossD_fake)/2
        disc.zero_grad()
        lossD.backward()
        opt_disc.step()

        ##train generator min log(1- D(G(
