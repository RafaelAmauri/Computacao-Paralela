#include <stdio.h>
#include <stdlib.h>

/*
====================================
Tempo Paralelo - Static
====================================

test passed

 Performance counter stats for './a.out':

       5282,864262      task-clock (msec)         #    1,971 CPUs utilized          
               672      context-switches          #    0,127 K/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
               177      page-faults               #    0,034 K/sec                  
    11.877.497.869      cycles                    #    2,248 GHz                      (49,92%)
    24.360.287.643      instructions              #    2,05  insn per cycle           (74,99%)
     3.152.911.037      branches                  #  596,818 M/sec                    (75,10%)
           253.301      branch-misses             #    0,01% of all branches          (74,98%)

       2,679990666 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       5637,663356      task-clock (msec)         #    1,676 CPUs utilized          
               515      context-switches          #    0,091 K/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
               178      page-faults               #    0,032 K/sec                  
    11.805.863.529      cycles                    #    2,094 GHz                      (50,05%)
    24.340.936.323      instructions              #    2,06  insn per cycle           (75,04%)
     3.153.524.119      branches                  #  559,367 M/sec                    (74,99%)
           231.210      branch-misses             #    0,01% of all branches          (74,97%)

       3,364685248 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       7302,350713      task-clock (msec)         #    1,843 CPUs utilized          
               616      context-switches          #    0,084 K/sec                  
                 2      cpu-migrations            #    0,000 K/sec                  
               176      page-faults               #    0,024 K/sec                  
    11.750.760.495      cycles                    #    1,609 GHz                      (49,99%)
    24.283.869.458      instructions              #    2,07  insn per cycle           (75,02%)
     3.149.839.163      branches                  #  431,346 M/sec                    (75,05%)
           234.349      branch-misses             #    0,01% of all branches          (74,96%)

       3,962738130 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       5838,765439      task-clock (msec)         #    1,634 CPUs utilized          
               497      context-switches          #    0,085 K/sec                  
                 2      cpu-migrations            #    0,000 K/sec                  
               176      page-faults               #    0,030 K/sec                  
    11.765.515.246      cycles                    #    2,015 GHz                      (49,87%)
    24.277.568.830      instructions              #    2,06  insn per cycle           (74,97%)
     3.153.754.265      branches                  #  540,141 M/sec                    (75,06%)
           203.524      branch-misses             #    0,01% of all branches          (75,06%)

       3,573240615 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       4909,403203      task-clock (msec)         #    1,853 CPUs utilized          
               423      context-switches          #    0,086 K/sec                  
                 1      cpu-migrations            #    0,000 K/sec                  
               177      page-faults               #    0,036 K/sec                  
    11.735.674.946      cycles                    #    2,390 GHz                      (50,03%)
    24.303.519.073      instructions              #    2,07  insn per cycle           (75,05%)
     3.149.830.699      branches                  #  641,591 M/sec                    (75,07%)
           203.797      branch-misses             #    0,01% of all branches          (74,90%)

       2,649629679 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       4908,133366      task-clock (msec)         #    1,853 CPUs utilized          
               421      context-switches          #    0,086 K/sec                  
                 2      cpu-migrations            #    0,000 K/sec                  
               178      page-faults               #    0,036 K/sec                  
    11.743.752.533      cycles                    #    2,393 GHz                      (49,98%)
    24.330.283.152      instructions              #    2,07  insn per cycle           (75,07%)
     3.149.921.765      branches                  #  641,776 M/sec                    (74,98%)
           199.750      branch-misses             #    0,01% of all branches          (75,04%)

       2,649409495 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       4899,191665      task-clock (msec)         #    1,855 CPUs utilized          
               418      context-switches          #    0,085 K/sec                  
                 0      cpu-migrations            #    0,000 K/sec                  
               177      page-faults               #    0,036 K/sec                  
    11.735.455.553      cycles                    #    2,395 GHz                      (49,94%)
    24.308.431.224      instructions              #    2,07  insn per cycle           (75,00%)
     3.151.370.153      branches                  #  643,243 M/sec                    (75,06%)
           188.096      branch-misses             #    0,01% of all branches          (74,99%)

       2,641023311 seconds time elapsed

test passed

 Performance counter stats for './a.out':

       5614,751829      task-clock (msec)         #    1,897 CPUs utilized          
               477      context-switches          #    0,085 K/sec                  
                 1      cpu-migrations            #    0,000 K/sec                  
               177      page-faults               #    0,032 K/sec                  
    11.835.549.528      cycles                    #    2,108 GHz                      (50,04%)
    24.278.991.308      instructions              #    2,05  insn per cycle           (75,01%)
     3.151.381.720      branches                  #  561,268 M/sec                    (74,99%)
           237.476      branch-misses             #    0,01% of all branches          (74,97%)

       2,960514887 seconds time elapsed
*/


int main() 
{
    int i, j, n = 30000; 
    
    omp_set_num_threads(2);

    // Allocate input, output and position arrays
    int *in = (int*) calloc(n, sizeof(int));
    int *pos = (int*) calloc(n, sizeof(int));   
    int *out = (int*) calloc(n, sizeof(int));   
    
    // Initialize input array in the reverse order
    #pragma omp parallel for schedule(guided)
    for(i=0; i < n; i++)
        in[i] = n-i;
    
    // Print input array
    //   for(i=0; i < n; i++) 
    //      printf("%d ",in[i]);
    
    // Silly sort (you have to make this code parallel)
    #pragma omp parallel for collapse(2) schedule(guided)
    for(i=0; i < n; i++)
        for(j=0; j < n; j++)
            if(in[i] > in[j]) 
            pos[i]++;	
    
    // Move elements to final position
    #pragma omp parallel for schedule(guided)
    for(i=0; i < n; i++) 
        out[pos[i]] = in[i];
    
    // print output array
    //   for(i=0; i < n; i++) 
    //      printf("%d ",out[i]);
    
    // Check if answer is correct
    #pragma omp parallel for schedule(guided)
    for(i=0; i < n; i++)
        if(i+1 != out[i]) 
        {
            printf("test failed\n");
            exit(0);
        }
    
    printf("test passed\n"); 
}
