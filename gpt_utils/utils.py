import json
from bson.json_util import loads
from bson.objectid import ObjectId
import time
import openai
from gpt_utils import *
from bson.objectid import ObjectId
import datetime
from functools import reduce


def deep_get(dictionary, keys, default=None):
    return reduce(lambda d, key: d.get(key, default) if isinstance(d, dict) else default, keys.split("."), dictionary)

def get_description_from_gpt(item):

    print('Product Model',item['Product']['Model'])

    openai.api_key = "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"

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


    default = "Write 15 product description for " + str(item['Product']['Model']) + ": \n----\n"

    l1 = data1.split('..')

    prompt1 = key_prompt(default, l1)

    response = openai.Completion.create(engine='davinci', prompt=prompt1, stop=['\n-', '-', 'Keys'], temperature=0.9,
                                        max_tokens=350, n=25)

    text_list = []

    for j in range(0, len(response["choices"])):
        if response["choices"][j]['text'] != '' and response["choices"][j]['text'] != ' ':
            text = response["choices"][j]['text']
            text = clean(text)
            text = " ".join([ll.rstrip() for ll in text.splitlines() if ll.strip()])
            if len(text)>150:
                text_list.append(text)

    list2 = list(filter(None, text_list))
    print("Description Completed succesfully ")
    time.sleep(1)

    return list2


def convert_int_to_roman(integer):
    intToroman = {1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X', 40: 'XL',
                  50: 'L', 90: 'XC', 100: 'C', 400: 'XD', 500: 'D', 900: 'CM', 1000: 'M'}

    # Descending intger equivalent of seven roman numerals
    print_order = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    roman_num = ''
    for x in print_order:
        if integer != 0:
            quotient = integer // x
            # If quotient is not zero output the roman equivalent
            if quotient != 0:
                for y in range(quotient):
                    roman_num += intToroman[x]
            # update integer with remainder
            integer = integer % x
    return roman_num


def upload_json_to_db(collection, file_name):
    data = json.load(open(file_name, 'r'))
    data = json.dumps(data)
    data = loads(data)
    collection.insert_many(data)


def update_db(collection, name,item, description):
    collection.update_one({'_id': ObjectId(item['_id'])},
                          {'$set': {'Description.' + str(name): description }})


def get_description(collection, count):
    current_index = 0


    for ind,item in enumerate(collection.find().batch_size(10)):
        del item['Time']['Scraped']
        print('Current product is', item['_id'])
        with open("last_entry.txt", "w") as file:
            file.write(str(current_index))
        current_index += 1

        description_list = get_description_from_gpt(item)
        len_list=0
        for i in range(count):
            try:
                len_list += 1
                if len(description_list)< len_list:
                    continue
                if item['Description'][str(convert_int_to_roman(i + 1))] == None:
                    update_db(collection, str(convert_int_to_roman(i + 1)), item,description_list[i])

            except Exception as e:
                print('Update db error is',e)




def get_description_after_error(collection, count):

    with open("last_entry.txt", "r") as file1:
        index = int(file1.read())
        current_index = index


    for ind,item in enumerate(collection.find().skip(index).batch_size(10)):
        print('Current product is', item['_id'])
        with open("last_entry.txt", "w") as file2:
            file2.write(str(current_index))
        current_index += 1
        description_list = get_description_from_gpt(item)
        len_list = 0

        for i in range(count):
            try:
                len_list += 1
                if len(description_list) < len_list:
                    continue
                if item['Description'][str(convert_int_to_roman(i + 1))] == None:
                    update_db(collection, str(convert_int_to_roman(i + 1)), item, description_list[i])

            except Exception as e:
                print('Update db error is',e)



