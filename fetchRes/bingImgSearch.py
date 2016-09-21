import urllib
from HTMLParser import HTMLParser
import os
import json
import io
words = []


def getResource(urlpath, savePath):
    urllib.urlretrieve(urlpath, savePath)


class BingImgParser(HTMLParser):
    index = 1
    word = ""
    path = ""

    def __init__(self, word, path):
        HTMLParser.__init__(self)
        self.word = word
        self.path = path

    def handle_starttag(self, tag, attrs):
        if tag == "img":
            for key, value in attrs:
                if key == "src" and "mm.bing.net" in value:
                    self.index = self.index + 1
                    getResource(value, os.path.join(
                        self.path, self.word + str(self.index) + ".jpeg"))


def getImg(w, path):
    filehandle = urllib.urlopen(
        'http://cn.bing.com/images/search?q=' + w + '&go=%E6%90%9C%E7%B4%A2&qs=bs&form=QBIR')
    parser = BingImgParser(w, path)
    parser.feed(filehandle.read())


def getaudio(w, path):
    jsonResult = urllib.urlopen(
        'http://xtk.azurewebsites.net/BingDictService.aspx?Word=' + w)
    jsonfile = io.open(path + '/' + w + '.json', 'w', encoding='utf-8')

    jsonObj = json.load(jsonResult)
    jsonfile.write(unicode(json.dumps(jsonObj,
                                      ensure_ascii=False, encoding='utf-8')))

    jsonfile.close()

    amEmp3URL = jsonObj['pronunciation']['AmEmp3']
    getResource(amEmp3URL, path + '/' + w +
                amEmp3URL[amEmp3URL.rindex('.'):])

wordList = open('CET4WordList.txt', 'r')


for line in wordList:
    line = line.lstrip()
    try:
        word = line[:line.index(' ')]
        if len(word) != 0:
            words.append(word)
    except Exception as e:
        pass
wordList.close()

logfile = open('log.txt', 'wb')

count = len(words)
for word in words:
    try:
        count -= 1
        print count, word
        path = os.path.abspath('.') + "/" + word + "/"
        if not os.path.exists(path):
            os.mkdir(path)
        else:
            continue

        path = os.path.abspath(path)
        getImg(word, path)
        getaudio(word, path)
        logfile.write(word)
        logfile.write('\n')

    except Exception as e:
        print e
        continue
    finally:
        logfile.flush()
logfile.close()
