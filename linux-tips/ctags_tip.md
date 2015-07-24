#使用vim + cscope + ctags 阅读c源码技巧1：ctags技巧

ctags -R  "build ctags index files"
cscope -Rbkq  "build cscope index files"

:cs add cscope.out  "input this command in vim, then we can use ':cscope find xx xx' command in vim directly"

ctrl + ]  : jump to define(global define, use "gd" to jump to local variable)
ctrl + t  : return back

[+{ : jump to last matched '{' in the same range level
]+} : jump to next matched '}'

{ : jump to last space line
} : jump to next space line

[+[ : jump to starting of last function
]+] : jump to starting of next function

* : jump to next position where current keywords appear
# : jump to last position where current keywords appear
