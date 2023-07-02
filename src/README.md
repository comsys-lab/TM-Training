1. setup data in input files
    topology_setup.c topology_setup.h
    config_setup.c   config_setup.h
    
    define structure (topo_struct, config_struct)
    Read all data in config_data.cfg and each layer in topo_data.csv


2. hm_dnn.c -> main source file
    Run topology_setup.c & config_setup.c 
        : Make error message for each step to make easier during debugging.
    

    Run single_layer_data_access_analysis.c & single_layer_baseline_energy.c n times(n: number of layers, use loop).
        : Check the number of accesses for all data. (assume HBM-only memory system)
        : This analysis results will be the minimum access time for each data(same as baseline).
    
    Run single_layer_baseline_energy.c
        : Calculate energy consumption in the case of running HBM-only baseline.
        : Consider ofmap write energy.

    //check off-chip memory hierarchy whether it is "vertical" or "horizontal".
    Run single_layer_ver.c (or single_layer_hor.c)
        : Identify where to store each data.



3. single_layer_sim -> run simulation for single layer.


4. data access analysis
ifmap -> ifmap operand -> fill '-1' value considering systolic array size -> concatenated operand


5. 