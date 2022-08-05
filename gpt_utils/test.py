import pymongo
from utils import *
import argparse
from bson.objectid import ObjectId
import datetime
from functools import reduce


def deep_get(dictionary, keys, default=None):
    return reduce(lambda d, key: d.get(key, default) if isinstance(d, dict) else default, keys.split("."), dictionary)



if __name__ =='__main__':

    client = pymongo.MongoClient('mongodb://localhost:27017/')
    #create database name "product_description"
    db= client['Product_Description'] #change the name of database as per your wish
    collection = db['Product_sample'] #change the collection
    # item = collection.find({'_id':ObjectId('60e4ac9ab7e015e0a9b75809')})
    for ind,item in enumerate(collection.find()):
        print(item)
        # print('Product Model', item['Product']['Model'])
        print(str(deep_get(item,'Inside.Software.OS Version')).split(',')[0])




        try:
            data1 = str(deep_get(item, 'Product.Model')) + " features a " + str(deep_get(item, 'Display.Illumination')) + " " + "display having a screen resolution of " + \
                    str(deep_get(item, 'Display.Resolution (H x W)')) + " and pixel density " +\
                    str(deep_get(item, 'Display.Pixel Density')) + " Pixels with screen to body ratio of " + \
                    str(deep_get(item, 'Display.Illumination')) + ".. The rear camera consists of a " + \
                    str(deep_get(item, 'Camera.Back Camera.Resolution')) + " " + \
                    str(deep_get(item, 'Camera.Back Camera.Aperture (W)')) + " primary sensor with features like Autofocus and Digital Zoom for the selfie shooter, you will have a " + \
                    str(deep_get(item, 'Camera.Front Camera.Resolution')) + " " + \
                    str(deep_get(item, 'Camera.Front Camera.Aperture (W)')) + " main lens that gives satisfactory video calling and image results .." + \
                    str(deep_get(item, 'Product.Model')) + " which comes up with " + \
                    str(deep_get(item, 'Product.Storage')) + " and " + \
                    str(deep_get(item, 'Product.Generation')) + " with the height " + \
                    str(deep_get(item, 'Design.Height')) + " It comes with a thickness of " + \
                    str(deep_get(item, 'Design.Thickness')) + " and weight of " + \
                    str(deep_get(item, 'Design.Weight')) + " This device comes up with the " + str(deep_get(item,'Inside.Software.OS Version')).split(',')[0] + "with the powerful processor with cpu " + \
                    str(deep_get(item, 'Inside.Processor.CPU')) + " and the gpu designed to play games " + \
                    str(deep_get(item, 'Inside.Processor.GPU')) + " It is compact with " + \
                    str(deep_get(item, 'Inside.RAM.Type')) + " and the memory of " + \
                    str(deep_get(item, 'Inside.RAM.Capacity')) + ".. It offers an ample internal storage capacity of " + \
                    str(deep_get(item, 'Inside.Storage.Capacity')) + " and for the connectivity the device comes with WIFI and bluetooth of version" + \
                    str(deep_get(item, 'Inside.Wireless.Bluetooth Version')) + ".. " + \
                    str(deep_get(item, 'Product.Model')) + " to derive power the device uses " + \
                    str(deep_get(item, 'Inside.Battery.Type')) + "uses a massive " + \
                    str(deep_get(item, 'Inside.Battery.Capacity')) + " with a standup time of " + \
                    str(deep_get(item, 'Inside.Battery.Standby Time'))


        except Exception as e:
            print('Exception is',e)

    print('done')