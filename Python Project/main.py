# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import enum
import threading, queue
import try_except
import os
import time
import pandas as pd
import inspect
from multiprocessing import Queue, Manager


def train_set():
    set1 = {2, 1, 3, 1, 4, 5, 6, 2}
    set2 = {5, 2, 7, 8, 1, 9}
    print('set1 = {} {}\nset2 = {} {}'.format(set1, type(set1), set2, type(set2)))
    set3 = set1 & set2
    set4 = set1 | set2
    set5 = set1 - set2
    set6 = set1 ^ set2
    print("after doing set3 = set1 & set2,\nset1 = {}\nset2 = {}\nset3 = {}".format(set1, set2, set3))
    print("after doing set4 = set1 | set2,\nset1 = {}\nset2 = {}\nset4 = {}".format(set1, set2, set4))
    print("after doing set5 = set1 - set2,\nset1 = {}\nset2 = {}\nset5 = {}".format(set1, set2, set5))
    print("after doing set6 = set1 ^ set2,\nset1 = {}\nset2 = {}\nset6 = {}".format(set1, set2, set6))
    set6.clear()
    print('after doing set6.clear(),\nset6 = {}'.format(set6))
    print('original set1 = {}\noriginal set2 = {}'.format(set1, set2))
    set6 = set1.difference(set2)
    print('after doing set6 = set1.difference(set2),\nset1 = {}\nset2 = {}\nset6 = {}'.format(set1, set2, set6))
    set6 = set6.clear()
    print('after doing set6.clear(),\nset6 = {}'.format(set6))
    print('original set1 = {}\noriginal set2 = {}'.format(set1, set2))
    set6 = set1.difference_update(set2)  # Attention: the expression can't be assigned to a variable
    print('after doing set6 = set1.difference_update(set2),\nset1 = {}\nset2 = {}\nset6 = {}'.format(set1, set2, set6))
    set1 = {1, 2, 3, 4, 5, 6}
    print('original set1 = {}\noriginal set2 = {}'.format(set1, set2))
    set6 = set1.intersection(set2)
    print('after doing set6 = set1.intersection(set2),\nset1 = {}\nset2 = {}\nset6 = {}'.format(set1, set2, set6))
    set1.isdisjoint(set2)
    print('after doing set1.isdisjoint(set2),\nset1 = {}\nset2 = {}\n'.format(set1, set2), set1.isdisjoint(set2))
    a = set1.pop()
    print('set1 = {}\na = {}'.format(set1, a))
    set1.update([9, 8, 0])
    print(set1)
    str1 = 'JHGYASH-186573-jkbaf-*&^$#'
    list1 = str1.split('-')
    print('list1 = {}'.format(list1))
    print('join the list1 gets:\n{}'.format('hello'.join(list1)))


def character():
    char = 'advancedpackagetools'
    print('the number of the specific character in the \'char\' is:\n{}'.format(char.count('ad')))
    print("the position of the specific character in the"
          "\'char\' first found is (by find()):\n{}".format(char.find('pack')))
    print("the position of the specific character in the"
          "\'char\' first found is (by rfind()):\n{}".format(char.rfind('pack')))
    print(char.strip('slda'))


def forcycle():
    '''
    演示 for() 函数的使用
    '''
    alist = list(input('input a number list:'))
    adict = {'ten': 10, 'nine': 9, 'two': 2}
    print(sorted(alist))
    for ele, ele1 in adict.items():
        print('key = ', ele, ', value = ', ele1)
    print(forcycle.__doc__)
    print([ele for ele in dir(pd) if not ele.startswith('_')])


def thread2() -> None:
    ''' 子线程2，由子线程1绑定与启动 '''
    print('Now subthread thread2 starts!')
    time.sleep(3.0)
    print('thread2 has running 3s!')
    print('thread2 running over!')


def thread1() -> None:
    ''' 子线程1 绑定子线程2，启动子线程2 '''
    print('subthread thread1 starts!')
    t2 = threading.Thread(target=thread2)
    t2.setDaemon(False)
    t2.start()
    print('thread1 has running 1 second!')
    for i in range(2, 6):
        time.sleep(1.0)
        print(f'thread1 has running {i} seconds!')
    print('thread1 running over!')


class Animal(object):
    name = 'puppy dog'

    def __init__(self, name):
        self.name = name
        print('class variable :', name)

    @classmethod
    def clsmod_print(cls):
        print('previous class variable value :', cls.name)
        cls.name = 'puppy love'
        print('after change :', cls.name)
        print('after change:', Animal.name)


def use_thread() -> None:
    ''' 主线程，绑定子线程1，启动子线程1 '''
    print('\nNow main thread starts!')
    t1 = threading.Thread(target=thread1())
    t1.setDaemon(False)
    t1.start()
    for j in range(3):
        print(f'quit after: {3-j} seconds!')
        time.sleep(1.0)
    print('main thread running over!')


l = []
locks = threading.Lock()
def test(n):
    locks.acquire()
    l.append(n)
    print(l)
    locks.release()


def thread():
    for i in range(0, 10):
        th = threading.Thread(target=test, args=(i,))
        th.start()


FolderPath = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
another_path = os.path.abspath(inspect.getfile(inspect.currentframe()))


def trypy(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    import this
    print(40*'-')                        # 输出 40 个 ‘-’
    print('{:40}'.format('-------Welcome to Python\'s World!-------'))
    # type or call yours code or functions/methods here
    # train_set()
    # character()
    # forcycle()
    # try_except.myprint()
    # use_thread()
    thread()
    print(Animal.name)
    Animal.clsmod_print()
    print(f'the dict = {Manager().dict()}')
    print('{:^40}'.format('Pycharm'))     # '-':以‘-’填充;'^':数据居中对齐;'40':数据宽度
    print(40*'-')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
