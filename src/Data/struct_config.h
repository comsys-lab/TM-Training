struct CONFIG {
    char run_name[100];
    int systolic_row;
    int systolic_col;
    int ifmap_buffer;
    int weight_buffer;
    int ofmap_buffer;

    char offchip_hierarchy[20];

    int tier1_bandwidth;
    int tier1_read_latency;
    int tier1_write_latency;
    int tier1_read_energy_perbit;
    int tier1_write_energy_perbit;
    int tier1_static_power_perGB;

    int tier2_bandwidth;
    int tier2_read_latency;
    int tier2_write_latency;
    int tier2_read_energy_perbit;
    int tier2_write_energy_perbit;
    int tier2_static_power_perGB;

    int page_size;
    int TLB_entry;
    int TLB_hit_latency;
    int TLB_miss_penalty;
};