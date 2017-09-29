# this逃逸


构造函数在返回之前其它线程就持有该对象的引用。


this逃逸经常发生在构造函数中启动线程或注册监听器时。


[Safe construction techniques](https://www.ibm.com/developerworks/java/library/j-jtp0618/index.html)
