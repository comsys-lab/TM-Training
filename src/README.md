1. setup data in input files
    topology_setup.c topology_setup.h
    config_setup.c   config_setup.h
    
    define structure (topo_struct, config_struct)
    Read all data in config_data.cfg and each layer in topo_data.csv


2. hm_dnn.c -> main source file
    (1) Run topology_setup.c & config_setup.c 
        : Make error message for each step to make easier during debugging.
    

    (2)loop{
    Run single_layer_data_access_analysis.c n times(n: number of layers, use loop).
        : Check the number of accesses for all data. (assume HBM-only memory system)
        : This analysis results will be the minimum access time for each data(same as baseline).
    
    Run single_layer_baseline_energy.c n times
        : Calculate energy consumption in the case of running HBM-only baseline.
        : Consider ofmap write energy.
    }


    (3)//check off-chip memory hierarchy whether it is "vertical" or "horizontal".
    Run single_layer_ver.c (or single_layer_hor.c)
        : Identify where to store each data (tier1, tier2 or tier3).
    Run write_single_layer_output.c
        : Write runtime overhead in one layer (Both on terminal and csv files).
    

    (4)
    Run write_total_output.c
        : Write runtime overhead and energy consumption for total layers.



3. topology_setup.c 
    : Define struct -> Read data in csv file, and assign csv data to struct.


4. config_setup.c
    : Define struct -> Read data in cfg file, and assign csv data to struct.


5. single_layer_data_access_analysis.c
    : Define ifmap and indexing 
    -> ifmap operand 
    -> fill '-1' value considering systolic array size 
    -> concatenated operand 
    -> duplicate and concatenate(considering num_filter/systolic_size)
    -> Read index and access counting


6. single_layer_baseline_energy.c
    : (total number of accesses) x (ReadEnergy) + (number of OFMAP data) x (WriteEnergy)


7. buffer_miss_timing.c
    : Calculate the time required for active buffer miss.
    Use Concatenated operand matirx.
    Dimension of concatenated operand matrix: (rxc)
    Dimension of read portion of the matrix when prefetching is done: (rxc') 
    active buffer miss time (Tb)= c' + r


8. single_layer_ver.c
    (1) Tier 1 as a buffer.
        Calculate the number of prefetches from tier1 to on-chip buffer until a miss occurs in tier 1 (N).
        Calculate the time required for prefetching from tier2 to inactive area of tier1 (T21).
        Time taken until miss occurs in tier 1 = Tb x N
        Check if prefetching from tier 2 to tier 1 is complete until miss occurs in tier 1. If not completed, calculate overhead.


    (2) Tier 1 as a cache.
        Use AMAT to calculate runtime overehead.
        Use single_layer_data_access_analysis.c
        If a miss occurs in tier1, read the data from tier 2 in units of page size (4KB).
        If each input data in a specific layer is accessed 1.x times on average, 
        we can simplify and calculate how many times memory requests can access the 4KB data.


8. single_layer_hor.c
    (1) Ideal address translation


    (2) Naive address translation


    (3) Ideal data placmenet


    (4) Naive data placement




9. write_single_layer_output.c




10. write_total_output.c

