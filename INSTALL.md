# Installation

## Installing the dependencies

To install the software, you will first need to install the GNU Scientific Library. To do so, you must download
the library. Fortunately, this is quite easy:

```
$ git submodule init
$ git submodule update
$ cd lib/gsl
$ ./configure
$ make
$ make install
```

This might take some time to build, so sit back, and enjoy a cup of coffee!

## Building the project

To build the project and run all tests, you simply need to run the make command.

```
$ make
```

You may then use PerfectSense as follows:

```
$ ./bin/perfectsense -f <data file> -o <output file> -c <configuration file>
```
