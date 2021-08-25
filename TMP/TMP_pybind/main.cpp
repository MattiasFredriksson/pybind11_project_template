﻿// DTW_python.cpp : Defines the entry point for the application.
//
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>

#include <pybind11_eigen_tensor.h>
#include <pybind11/pybind11.h>

#include "TMP/test.h"

#ifndef PROJECT_NAME_DEF
#define PROJECT_NAME_DEF no_name_test
#endif

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
	return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(PROJECT_NAME_DEF, m) {
	m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: cmake_example
        .. autosummary::
           :toctree: _generate
           add
           subtract
           sq
    )pbdoc";

	m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

	m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers
        Some other explanation about the subtract function.
    )pbdoc");

	m.def("sq", &sq<int>, R"pbdoc(
        Square a number
        Imported test function.
    )pbdoc");

#ifdef VERSION_INFO
	m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
	m.attr("__version__") = "dev";
#endif
}