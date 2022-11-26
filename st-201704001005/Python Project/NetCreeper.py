import re
import requests
import os
import logging
import inspect
from _datetime import datetime
import time
# import urllib.request

# 当前文件所在目录
DirPath = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
# 以日期作为文件名
year = str(time.localtime().tm_year)
mon = time.localtime().tm_mon
day = time.localtime().tm_mday
if mon < 10:
    mon = '0' + str(mon)
else:
    mon = str(min)
if day < 10:
    day = '0' + str(day)
else:
    day = str(day)
dynamic_dir = year + mon + day

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('NetCreeper')

def get_html_text(url):
    """
       @function: 获取页面内容并将其转化为 .txt
       @:parameter: 页面url
       @:return: 页面内容的 .text 格式
    """
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
                      "Chrome/103.0.5060.114 Safari/537.36 Edg/103.0.1264.62"}

    response = requests.get(url, headers=headers, timeout=1)
    if response is not None:
        logger.info(f'{datetime.now()}--information has been extracted from the url.')
    with open('E:\\图片\\'+dynamic_dir+'.txt', mode='w+b') as fd:
        fd.write(response.content)
    fd.close()
    return response.text

def parse_html_text(html_text):
    """
        @function: 解析 .txt 文本，利用正则表达获取图片的 url
        @:parameter: 获取的 html_text
        @:return: 包含所有图片 url 的列表 url_list
    """
    # | 具有很低的优先级
    re_exp = re.compile(r'https?://tse.*?pid=\d.*?[.]\d')
    url_list = re.findall(re_exp, html_text)
    pattern = r'https?://.*?\.jpg'
    url_list.extend(re.findall(pattern, html_text, re.MULTILINE))
    logger.info(f'{datetime.now()}--original picture urls has been extracted:{url_list}')
    for i in range(len(url_list)):
        if url_list[i].endswith('.jpg'):
            url_list[i] = url_list[i][url_list[i].rindex('http'):]
    i = 0
    while i < len(url_list):
        if url_list[i].count('://') == 0:
            del url_list[i]
            i -= 1
        else:
            i += 1
    logger.info(f'{datetime.now()}--final picture urls has been extracted:{url_list}')
    # 转换为集合，去除重复项
    return set(url_list)

def download_func(filepath, each_url):
    """
        @function: 图片下载具体实现
        @:parameter: 图片存储的路径 filepath，每张图片的 url each_url
        @:return: None
    """
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
                      "Chrome/103.0.5060.114 Safari/537.36 Edg/103.0.1264.62"}
    # 若下载出现异常，跳过该图片的下载
    try:
        response = requests.get(each_url, headers=headers, timeout=1)
    except Exception as e:
        logger.info(f'{e}')
    else:
        with open(filepath, mode='wb') as fd:
            fd.write(response.content)
        fd.close()

def auto_download():
    url = 'https://cn.bing.com/images/search?q=%E7%94%B5%E8%84%91%E5%A3%81%E7%BA%B8%E9%A' \
          'B%98%E6%B8%85%E5%85%A8%E5%B1%8F%E5%8A%A8%E6%BC%AB&form=IQFRML&first=1&tsc=ImageHoverTitle&cw=1404&ch=720'
    html_text = get_html_text(url)
    url_list = parse_html_text(html_text)
    i = 0
    for pic_url in url_list:
        filename = dynamic_dir + '-' + str(i)
        i += 1
        filepath = 'E:\\图片\\picture\\' + filename + '.jpg'
        download_func(filepath, pic_url)
        print(f'{datetime.now()}--the {i}th picture {os.path.basename(filepath)} has been downloaded '
                    f'in directory {os.path.dirname(filepath)}')

if __name__ == '__main__':
    auto_download()
