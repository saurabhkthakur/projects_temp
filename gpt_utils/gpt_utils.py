import re
from rake_nltk import Rake
r = Rake()
def clean(text):
    text = text.rstrip()
    text = text.lstrip()
    bad_chars = [';', ':', '!', "*"]
    text = re.sub(r'^https?:\/\/.*[\r\n]*', '', text)
    text = re.sub(r'http\S+', '', text)
    text = re.sub(r'\.+:', ".", text)
    text = re.sub(r'@ www', "", text)
    text = re.sub(' "+', ' ', text)
    text = re.sub(' :', ' ', text)
    text = text.replace("\\", "")
    text = text.split(".")
    text.pop()
    text1 = ""
    for i in range(len(text)):
        if len(text[i].split()) < 6:
            continue
        else:
            text1 += text[i] + ". "
    for i in bad_chars:
        text1 = text1.replace(i, '')
    text1 = text1.replace('``', '')
    text1 = text1.replace('[', '')
    text1 = text1.replace('(', '')
    text1 = text1.replace(')', '')
    text1 = text1.replace(']', '')
    text1 = text1.replace('keywords', '')
    return text1


def post_process(text_list):  # TO_DO custom content filtering
    post_list = ["mt"]
    for text in text_list:
        print(text, " <last element>", text[-1])
    return post_list


def listToString(s):
    str1 = ""

    # return string  list
    return (str1.join(s))


def checksentece(string):
    length = len(string)
    if string[length - 1] != '.':
        return False

def key_prompt(default, ads_text):
    #putting together prompt and generating titles
    texts = []
    for text in ads_text:
        r.extract_keywords_from_text(text)
        text = 'Keys: ' + r.get_ranked_phrases()[0] + '.\n' + text
        texts.append(text)
    texts = "\n----\n".join(list(set(texts)))
    prompt = default + texts + "\n----\nKeys: " +'.\n'
    return prompt