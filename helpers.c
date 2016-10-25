/**
 * helpers.c
 *
 * CS50 AP
 * Problem 3-6
 *
 * Helper functions.
 */
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int min, int max)
{
    if (max - min < 2) 
    {
        if (values[max] == value || values[min] == value) 
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    if ((max + 1 - min) % 2 == 0) 
    {
        if (values[(max + min + 1) / 2] < value) 
        {
            min = (max + min + 1) / 2 + 1;
            
        }
        else if (values[(max + min + 1) / 2] > value) 
        {
            max = (max + min + 1) / 2 - 1;
        }
        else if (values[(max + min + 1) / 2] == value 
        || (values[(max + min - 1) / 2] == value)) 
        {
            return 1;
        }
    }
    else 
    {
        if (values[(max + min) / 2] < value) 
        {
            min = (max + min) / 2 + 1;
            
        }
        else if (values[(max + min) / 2] > value) 
        {
            max = (max + min) / 2 - 1;
        }
        else if (values[(max + min) / 2] == value 
        || (values[(max + min + 2) / 2] == value) 
        || (values[(max + min - 2) / 2] == value)) 
        {
            return 1;
        }
    }
    if (values[min] == value || values[max] == value) 
    {
        return 1;
    }
    
    if (search(value, values, min, max)) 
    {
        return 1;
    } else 
    {
        return 0;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int j;
    // counter for sorting through sorted nums
    int tempInt;
    // tempInt is a temporary int for switching ints
    
    for (int i = 1; i < n; i++) 
    {
        j = i;
        while (values[j] < values[j - 1]) 
        {
            // keeps on switching value to the left until it is correct
            tempInt = values[j];
            values[j] = values[j - 1];
            values[j - 1] = tempInt;
            if (j == 0) 
            {
                break;
            }
            j--;
        }
    }
    return;
}