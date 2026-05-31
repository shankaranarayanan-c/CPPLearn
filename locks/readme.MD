## Comparing the Performance

The following is the perf output for aggressive spin lock

```
 Performance counter stats for './threadlocks 1':

    23,462,018,653      task-clock                       #   20.990 CPUs utilized             
             8,424      context-switches                 #  359.048 /sec                      
               836      cpu-migrations                   #   35.632 /sec                      
             2,211      page-faults                      #   94.237 /sec                      
     1,157,355,979      cpu_atom/instructions/           #    0.03  insn per cycle              (97.89%)
     7,027,264,184      cpu_core/instructions/           #    0.11  insn per cycle              (78.52%)
    34,263,003,367      cpu_atom/cycles/                 #    1.460 GHz                         (97.89%)
    65,338,354,041      cpu_core/cycles/                 #    2.785 GHz                         (78.52%)
       204,534,920      cpu_atom/branches/               #    8.718 M/sec                       (97.89%)
     1,182,462,554      cpu_core/branches/               #   50.399 M/sec                       (78.52%)
           239,484      cpu_atom/branch-misses/          #    0.12% of all branches             (97.89%)
           821,630      cpu_core/branch-misses/          #    0.07% of all branches             (78.52%)
 #     98.7 %  tma_backend_bound        (97.89%)
 #     95.9 %  tma_backend_bound      
                                                  #      0.1 %  tma_bad_speculation    
                                                  #      0.7 %  tma_frontend_bound     
                                                  #      3.3 %  tma_retiring             (78.52%)
 #      0.6 %  tma_retiring             (97.89%)
 #      0.0 %  tma_bad_speculation    
                                                  #      0.6 %  tma_frontend_bound       (97.89%)

       1.117763126 seconds time elapsed

      23.280824000 seconds user
       0.237782000 seconds sys
 ```

 The following is the perf output for optimized locking for spinlock
 ```
 Performance counter stats for './threadlocks 2':

   142,918,057,152      task-clock                       #   21.769 CPUs utilized             
            48,698      context-switches                 #  340.741 /sec                      
             5,336      cpu-migrations                   #   37.336 /sec                      
             2,210      page-faults                      #   15.463 /sec                      
   628,482,270,539      cpu_atom/instructions/           #    2.83  insn per cycle              (89.59%)
 1,337,520,611,362      cpu_core/instructions/           #    2.85  insn per cycle              (68.52%)
   222,093,213,206      cpu_atom/cycles/                 #    1.554 GHz                         (89.59%)
   469,430,978,919      cpu_core/cycles/                 #    3.285 GHz                         (68.52%)
   209,104,527,358      cpu_atom/branches/               #    1.463 G/sec                       (89.59%)
   444,492,089,003      cpu_core/branches/               #    3.110 G/sec                       (68.52%)
         1,095,805      cpu_atom/branch-misses/          #    0.00% of all branches             (89.59%)
         2,161,259      cpu_core/branch-misses/          #    0.00% of all branches             (68.52%)
 #      0.4 %  tma_backend_bound        (89.59%)
 #     28.7 %  tma_backend_bound      
                                                  #      0.6 %  tma_bad_speculation    
                                                  #      7.3 %  tma_frontend_bound     
                                                  #     63.3 %  tma_retiring             (68.52%)
 #     47.2 %  tma_retiring             (89.59%)
 #      0.0 %  tma_bad_speculation    
                                                  #     52.4 %  tma_frontend_bound       (89.59%)

       6.565156504 seconds time elapsed

     142.845941000 seconds user
       0.104804000 seconds sys
 ```

The following is the perf output for standard Mutex

```
 Performance counter stats for './threadlocks 3':

       396,033,079      task-clock                       #    1.092 CPUs utilized             
             1,234      context-switches                 #    3.116 K/sec                     
               585      cpu-migrations                   #    1.477 K/sec                     
             2,209      page-faults                      #    5.578 K/sec                     
     5,811,694,266      cpu_atom/instructions/           #    5.65  insn per cycle              (91.84%)
     1,046,251,129      cpu_core/instructions/           #    3.43  insn per cycle              (80.33%)
     1,027,803,758      cpu_atom/cycles/                 #    2.595 GHz                         (91.84%)
       304,693,210      cpu_core/cycles/                 #    0.769 GHz                         (80.33%)
       968,862,488      cpu_atom/branches/               #    2.446 G/sec                       (91.84%)
       176,134,514      cpu_core/branches/               #  444.747 M/sec                       (80.33%)
            85,163      cpu_atom/branch-misses/          #    0.01% of all branches             (91.84%)
           177,251      cpu_core/branch-misses/          #    0.10% of all branches             (80.33%)
 #      3.5 %  tma_backend_bound        (91.84%)
 #     34.5 %  tma_backend_bound      
                                                  #      1.4 %  tma_bad_speculation    
                                                  #     12.7 %  tma_frontend_bound     
                                                  #     51.4 %  tma_retiring             (80.33%)
 #     94.4 %  tma_retiring             (91.84%)
 #      0.3 %  tma_bad_speculation    
                                                  #      1.9 %  tma_frontend_bound       (91.84%)

       0.362600613 seconds time elapsed

       0.332113000 seconds user
       0.088694000 seconds sys
```

The following is the perf output for hybrid lock or adaptive mutex

```
The output of counter is 1000

 Performance counter stats for './threadlocks 4':

       426,866,083      task-clock                       #    1.694 CPUs utilized             
             1,224      context-switches                 #    2.867 K/sec                     
               441      cpu-migrations                   #    1.033 K/sec                     
             2,210      page-faults                      #    5.177 K/sec                     
     3,665,574,531      cpu_atom/instructions/           #    4.48  insn per cycle              (91.28%)
     3,445,362,210      cpu_core/instructions/           #    4.53  insn per cycle              (82.32%)
       818,457,494      cpu_atom/cycles/                 #    1.917 GHz                         (91.28%)
       760,395,810      cpu_core/cycles/                 #    1.781 GHz                         (82.32%)
       612,773,992      cpu_atom/branches/               #    1.436 G/sec                       (91.28%)
       576,165,471      cpu_core/branches/               #    1.350 G/sec                       (82.32%)
           129,023      cpu_atom/branch-misses/          #    0.02% of all branches             (91.28%)
           211,017      cpu_core/branch-misses/          #    0.04% of all branches             (82.32%)
 #      6.9 %  tma_backend_bound        (91.28%)
 #     29.4 %  tma_backend_bound      
                                                  #      0.6 %  tma_bad_speculation    
                                                  #      4.4 %  tma_frontend_bound     
                                                  #     65.5 %  tma_retiring             (82.32%)
 #     75.4 %  tma_retiring             (91.28%)
 #      0.5 %  tma_bad_speculation    
                                                  #     17.2 %  tma_frontend_bound       (91.28%)

       0.251996788 seconds time elapsed

       0.361669000 seconds user
       0.086681000 seconds sys
```

#### Analysis

|Metric|Aggressive|Optimized|Mutex|Adaptive|
| ------------- |:-------------|:-------------|:-------------:|:-------------:|
|Elapsed Time|1.117s|6.565s|0.362s|0.251s (WINNER)|
|CPU Utilization|20.9 CPUs|21.7 CPUs|1.09 CPUs|	1.69 CPUs|
Context Switches|8,424|48,698|1,234|1,224 (LOWEST)|
Retiring (Core)|3.3%|63.3%|51.4%|65.5% (BEST)|
Backend Bound|95.9% (STALL)|28.7%|34.5%	|29.4% (CLEAN)|

1. 🚀 Speed Record (0.25s)
Option 4 is 30% faster than the Standard Mutex and 4x faster than the Aggressive Spinlock.

    Why?: By spinning for 1,000 iterations before sleeping, threads "catch" the lock while it is in the middle of being released. This avoids the expensive 5-microsecond penalty of a kernel sleep/wake cycle.

2. 🧠 Peak Architectural Efficiency (65.5% Retiring)
This is the highest "Retiring" score of all four tests.

    The Meaning: The CPU spent almost all its time actually finishing work. It wasn't waiting for the memory bus (like Option 1) and it wasn't spinning in a trillion-instruction circle (like Option 2).

3. 💤 Smart Resource Management
Even with 1,000 threads, it only used 1.69 CPUs.

    The Meaning: It is almost as "polite" as a standard mutex. It used just enough CPU to stay fast but put the "hopeless" threads to sleep to prevent the system from hanging.