# "Correct" implementation of CSD in QtWidget

https://www.qt.io/blog/custom-window-decorations

```
In Qt 5.15, we've added two new methods to QWindow: startSystemMove and startSystemResize. These methods ask the window manager to take over and start a native resize or move operation. This means snapping, tiling, etc.
```

Low level hacking using startSystemMove

https://github.com/qt/qtbase/blob/dev/tests/manual/startsystemmove/main.cpp


# Limitation

`startSystemResize()` isn't supported on macOS as 6.2.3. It seems isn't implemented by Apple at all.

TODO: explore `unifiedTitleAndToolBarOnMac` as alternative imp
https://doc.qt.io/qt-6/qmainwindow.html#unifiedTitleAndToolBarOnMac-prop


https://datagubbe.se/decusab/