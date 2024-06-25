# Установка приложения

## Предварительные требования

Для сборки и запуска данного проекта необходимы следующие инструменты и библиотеки:
- Qt 5.x (Core, Gui, Widgets, Sql)
- CMake 3.5 или выше
- Компилятор C++ (например, GCC для Linux, MSVC для Windows)
- SQLite

## Установка на Linux

### Шаг 1: Установка зависимостей

#### Установка Qt и CMake

```sh
sudo apt-get update
sudo apt-get install -y qt5-default qttools5-dev-tools cmake build-essential
sudo apt-get install -y sqlite3 libsqlite3-dev
```

### Шаг 2: Сборка проекта

```sh
mkdir build
cd build
```

#### Сгенерируйте файлы сборки с помощью CMake:

```sh
cmake ..
```

#### Соберите проект:

```sh
make
```

#### Запуск.

```sh
./MainWindow
```


## Установка на Windows

### Все почти то же что и в Linux

#### Я пользуюсь Linux, так что не помогу, попробуй сделать вот так:

##### Это писать нужно в папке где файлы приложения

```sh
mkdir build
cd build
```

```sh
cmake ..
```
```sh
nmake
```

## Запуск.

```sh
MainWindow.exe
```


