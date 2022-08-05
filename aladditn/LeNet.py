import torch
import torch.nn as nn

#Lenet architecture

class LeNet(nn.Module):
    def __init__(self):
        super(LeNet, self).__init__():
        self.relu = nn.ReLU
        self.Pool1 = nn.Pool
        self.conv1 = nn