"""a .py training file """
import urllib.parse
import urllib.request
import os, sys, time, logging, math, inspect
from datetime import datetime
from try_except import aa

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('can_recv')
hello = 'Hello World!'

def try_modbus(func):
    logger.info(f'{datetime.now()} : just a decorate sentence')
    def wrapper(*args, **kwargs):
        logger.info(f'{datetime.now()} : this is a decorate sentence')
        try:
            result = func(*args, **kwargs)       # execute the function first anyway
            print(f'entry {func}')
        except Exception as e:
            print(func, '_Fault:', e)
            result = None
        finally:
            print(result)
            return result
    return wrapper


@try_modbus
def dosome():
    print('How to use the decorate sentence')
    return list(range(1, 11))


def outer(x=0):
    def inner(y):
        print('y =',y)
    return inner


'python 的一些内置模块'
def sys_exe():
    print(sys.platform)
    for path in sys.path:
        # sys.path is a list
        print(path)
        for kt in sys.modules.keys():
            print('key =', kt)
    # print(sorted(sys.modules.keys()))

def os_exe():
    print(__file__)
    print(os.path.dirname(__file__))    # return the directory which the chose file in
    print(os.path.basename(__file__))   # return the chose file name
    print(os.path.abspath('\\main.py'))
    print(os.getcwd(), os.getpid(), os.getenv('PYTHONPATH'))
    # os.rename('a_train.py', 'can_recv.py')    # rename a file
    for kt,vt in os.environ.items():            # get the environment of the system
        print(kt, '->', vt)


def namespace():
    global_var = globals().copy()
    for kt, vt in global_var.items():
        print(kt, '->', vt)


def url_use():
    DirPath = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
    # data1 is bytes type, urlencode() transform dictionary to string
    data1 = bytes(urllib.parse.urlencode({'word': 'hello'}), encoding='utf-8')
    print(f"start time = {datetime.now()}")
    response = urllib.request.urlopen('http://httpbin.org/post', data=data1, timeout=0.5)
    print('response type is :', type(response))
    print('response status is :', response.status)
    print('response headers :', response.getheaders())
    print('response getheaders() :', response.getheader('Server'))
    print(f"end time = {datetime.now()}")
    with open(file=DirPath+r'\0724.txt',mode='w') as fd:
        # .decode() -> transform int(bytes) to string
        fd.writelines(response.read().decode())
    fd.close()
    with open(file=DirPath+r'\0724.txt',mode='r') as fd:
        rd = fd.readlines()
    fd.close()
    print(rd)
    # Request 对象更复杂的请求
    # Rq = urllib.request.Request('http://www.baidu.com')
    # response = urllib.request.urlopen(Rq)
    # print(response.read().decode('utf-8'))
    # Request post method
    # url = 'http://httpbin.org/post'
    # headers = {
    #     'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.198 Safari/537.36'
    # }
    # data = {'word': 'hello'}
    # data = bytes(str(data), encoding='utf-8')
    # req = urllib.request.Request(url=url, data=data, headers=headers, method='POST')
    # response = urllib.request.urlopen(req)
    # print(response.read().decode('utf-8'))
    # agent method
    url = 'http://httpbin.org'  # url地址
    handler = urllib.request.ProxyHandler({'http': '122.193.244.243:9999'})  # 使用request模块ProxyHandler类创建代理
    # handler = request.ProxyHandler({"http":"账号:密码@'122.193.244.243:9999'"})
    # 付费代理模式　
    opener = urllib.request.build_opener(handler)    # 用handler创建opener
    resp = opener.open(url,timeout=1)      # 使用opener.open()发送请求
    print(resp.read())           # 打印返回结果


if __name__ == '__main__':
    # dosome()
    # outer(4)(8)
    # print(dir(os))
    # sys_exe()
    # os_exe()
    # namespace()
    url_use()
    print('end')
else:
    print('module can_recv.py is invoked!')




