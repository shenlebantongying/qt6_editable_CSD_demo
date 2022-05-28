# "Correct" implementation of CSD in QtWidget

https://www.qt.io/blog/custom-window-decorations

```
In Qt 5.15, we've added two new methods to QWindow: startSystemMove and startSystemResize. These methods ask the window manager to take over and start a native resize or move operation. This means snapping, tiling, etc.
```

Low level hacking using startSystemMove

https://github.com/qt/qtbase/blob/dev/tests/manual/startsystemmove/main.cpp


https://datagubbe.se/decusab/