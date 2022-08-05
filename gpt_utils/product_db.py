import pymongo
import argparse

from utils import *


if __name__ =='__main__':

    client = pymongo.MongoClient('mongodb://localhost:27017/')
    #create database name "product_description"
    db= client['Product_Description_2'] #change the name of database as per your wish
    collection = db['Product_sample'] #change the collection

    parser = argparse.ArgumentParser(description='Get Product description.')
    parser.add_argument('-load_json', type=bool,default=False, help='import json file into mongo_db')
    parser.add_argument('-json_file_path', type=str,default='Product.json', help='import json file into mongo_db')
    parser.add_argument('-run', type=bool,default=False, help='Add description in db first time')
    parser.add_argument('-count', type=int, default=0,help='No of description need to add')
    parser.add_argument('-run_again', type=bool,default=False, help='Add description in db if error occurs')

    args = parser.parse_args()
    
    if args.load_json:
        upload_json_to_db(collection,args.json_file_path)
        print('Data Imported successfully')

    if args.run:
        get_description(collection,args.count)


    if args.run_again:
        get_description_after_error(collection,args.count)











