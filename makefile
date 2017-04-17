SHELL := /usr/bin/env bash

.PHONY: build
build:
	mkdir -p build && g++ -std=c++14 app.cpp -o build/stopwatch
