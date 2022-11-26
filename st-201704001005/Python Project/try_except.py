'''
测试 raise/traceback.exc() 异常处理
'''

print('here is try_except model~')
aa = list(range(10))

# 导入traceback模块
import traceback


class SelfException(Exception):
    pass


def try_main():
    firstMethod()


def firstMethod():
    secondMethod()


def secondMethod():
    thirdMethod()


def thirdMethod():
    raise SelfException("自定义异常信息")

def myprint():
    print('print \'myprint\'')


class mytrain:
    pity = 23
    def __init__(self):
        self.pupy = 1
        print('the class __init__ function')

    def pipy(self):
        print('pity =', self.pity)
        print('pupy =', self.pupy)

def CRC(*args):
    proof = 0xffff
    data_len = 8
    print('args = ', args)
    for i in args:
        proof ^= i
        j = 0
        while j < 8:
            if proof & 0x01 == 0x01:
                proof = (proof >> 1) ^ 0xa001
            else:
                proof >>= 1
            j += 1
    ret = (proof << 8) & 0xff00
    ret = ret | (proof >> 8)
    # ret = (proof >> 8) | ((proof << 8) & 0xff00)   # python 可以处理的数据很大，左移时要注意
    return ret

if __name__ == '__main__':
    # myprint()
    # try:
    #     try_main()
    # except:
    #     # 捕捉异常，并将异常传播信息输出控制台
    #     traceback.print_exc()
    #     # 捕捉异常，并将异常传播信息输出指定文件中
    #     traceback.print_exc(file=open('log.txt', 'a'))
    # else:
    #     print('Nothing happened')
    mm = mytrain()
    nn = mytrain()
    # mm.pipy()
    # nn.pipy()
    # mm.pupy = 10
    mm.pipy()
    nn.pipy()
    dat = [0xc0,0x01,0x04,0x02,0x03,0x00,0x00,0x00]
    print(hex(CRC(*dat)))
