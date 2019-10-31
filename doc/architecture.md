# PerfectSense architecture

## Project folder structure

Our project will follow a conventional file structure for C projects.

```
PerfectSense
│   README.md
|   INSTALL.md
|   LICENSE
|   .gitiggfcnore
|   .gitmodules
│   makefile
|       
│
└───src
│   │   fileio.c
│   │   fusion.c
│   │   timepoint.c
│   │   validation.c
│   │   argumentparser.c
│   │   main.c
│   │   utils.c
|
|
└───include
│   │   fileio.h
│   │   fusion.h
│   │   timepoint.h
│   │   validation.h
│   │   argumentparser.h
│   │   utils.h
|   
|
└───build
│   │   fileio.o
│   │   fusion.o
│   │   timepoint.o
│   │   validation.o
│   │   argumentparser.o
│   │   utils.o
|   |   main.o
|   
|   
└───bin
│   │   perfectsense
|
└───test
│   │   ...
|   |
│   └───files
│       │   test_case_1.txt
│       │   test_case_2.txt
│       │   ...
│   
└───lib
│   │   gsl (GNU Scientific Library)
|
└───doc
│   │   architecture.md
|   |   user_guide.md
|   |   code_documentation.md
```

## Schematic representation of the architecture

A schematic representation of the software's architecture is shown below:

![PerfectSense architecture](https://github.com/flexplicateur/PerfectSense/blob/master/doc/architecture.png?raw=true "PerfectSense Architecture")

## Description of the architecture

<div style="text-align: center"> 
We opted to separate the concerns in the PerfectSense software such that each aspect of the
data fusion process is managed in its own file defining a set of relevant functions. Here,
we provide a preliminary, high-level overview of the contents of these files.

For example, *parse_arguments.c* defines functions responsible for parsing the arguments
provided to the program via the command line. This involves ensuring that all necessary
arguments are provided, for example, and storing these arguments in a proper data structure.
The functions in *parse_arguments.c* are called from the *main* function.

The *fileio.c* file defines functions that are useful to read the input files, and write a
file with the results. Functions are defined for parsing the data file (in tsv/csv) format and
a configuration file which describes the parameters that are to be specified for the fusion
algorithm (sensor tolerance, comma or tab delimiter, etc.). The *read_data_file()* function
returns a *timepoint_collection_t* which is simply a wrapper structure for a set of
*timepoint_t* structures. The *timepoint_t* is a structure that stores a timestamp, as well
as the readings (and their associated sensors) that were taken at that particular timepoint.

Before proceeding to the fusion algorithm, the readings are validated with the functions defined
in the *validation.c* file. These functions find invalid readings (outside of the allowable range
specified in the configuration file) as well as the sensors which provide the same reading for a
prolonged period of time (defined in the configuration file).

The fusion algorithm defined in *fusion.c* is then applied to every *timepoint_t* in the
*timepoint_collection_t* via the *fuse_readings()* function. Every operation in the fusion
algorithm is defined in this file.

The fused readings are then written to a file with a *write_file()* function defined in *fileio.c*.

A file called *utils.c* defines a set of functions useful for debugging. These functions allow
the developer to print the various data structures used in the program to the console.

**NOTE: This is a preliminary architecture, which is subject to minor changes. Additional helper functions
may be implemented as needed to support these high level functions.**
</div>
