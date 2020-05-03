# High-Dimensional K-Means
An exploration of K-Means clustering in higher dimensions.

## Introduction
This R markdown file explores the performance of the `stat::kmeans` clustering function's performance on data in different dimensions.

The intent is to isolate and understand the impact of the curse of dimensionality on the performance of this technique.

## Status
The code in this repo is a work in progress.

## How to run this code
The code was written using R version 4.0, which is can be downloaded here: https://www.r-project.org/.  The code should be compatible with R version 3.6, although I haven't tested this.

The accompanying [prrmutations.cpp](https://github.com/chriswmann/high-dimensional-k-means/blob/master/prrmutations.cpp) contains a simple c++ routine to compute the permutations of a vector.

This is included because the predicted clusters are assigned at random and a brute force method of computing the appropriate labels to get the best accuracy is used.  With ten factors, this is 10! = 3,628,800 permutations.

The [gtools](https://cran.r-project.org/web/packages/gtools/index.html) package includes a `permutations` function which can be used instead, although the performance results in very long run times
with more than nine clusters.

Even with the lower-level permutations function in prrmutations, the code runs in the order of tens of minutes with ten clusters, as there are still portions of R code that run on the 3,628,800 label permutations that result from that many clusters.


