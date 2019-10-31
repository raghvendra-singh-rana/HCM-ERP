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
