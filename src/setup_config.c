#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_config.h"

#define MAX_LINE_LENGTH 100

void main() {
    struct CONFIG config;
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen("/home/jy/hm_overhead/input_files/config_files/template.cfg", "r");  // Replace "config.cfg" with your file name

    if (file == NULL) {
        printf("Failed to open the configuration file.\n");
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, "RunName") != NULL) {
            sscanf(line, "%*[^=]=%s", config.run_name);
        } else if (strstr(line, "SystolicSize") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.systolic_row);
            config.systolic_col = config.systolic_row;
        } else if (strstr(line, "IFMAPBuf_KB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.ifmap_buffer);
        } else if (strstr(line, "WeightBuf_KB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.weight_buffer);
        } else if (strstr(line, "OFMAPBuf_KB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.ofmap_buffer);
        } else if (strstr(line, "TierHierarchy") != NULL) {
            sscanf(line, "%*[^=]=%s", config.offchip_hierarchy);
        } else if (strstr(line, "Tier1Bandwidth_GBs") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_bandwidth);
        } else if (strstr(line, "Tier1ReadLatency_ns") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_read_latency);
        } else if (strstr(line, "Tier1WriteLatency_ns") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_write_latency);
        } else if (strstr(line, "Tier1ReadEnergyperBit_pJ") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_read_energy_perbit);
        } else if (strstr(line, "Tier1WriteEnergyperBit_pJ") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_write_energy_perbit);
        } else if (strstr(line, "Tier1StaticPower_mWpGB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier1_static_power_perGB);
        } else if (strstr(line, "Tier2Bandwidth_GBs") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_bandwidth);
        } else if (strstr(line, "Tier2ReadLatency_ns") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_read_latency);
        } else if (strstr(line, "Tier2WriteLatency_ns") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_write_latency);
        } else if (strstr(line, "Tier2ReadEnergyperBit_pJ") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_read_energy_perbit);
        } else if (strstr(line, "Tier2WriteEnergyperBit_pJ") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_write_energy_perbit);
        } else if (strstr(line, "Tier2StaticPower_mWpGB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.tier2_static_power_perGB);
        } else if (strstr(line, "PageSize_KB") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.page_size);
        } else if (strstr(line, "TLBEntry") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.TLB_entry);
        } else if (strstr(line, "TLBHitLatency_cycle") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.TLB_hit_latency);
        } else if (strstr(line, "TLBMissPenalty_cycle") != NULL) {
            sscanf(line, "%*[^=]=%d", &config.TLB_miss_penalty);
        }
    }

    fclose(file);

    /* For test
    printf("Run Name: %s\n", config.run_name);
    printf("Systolic Size: %dx%d\n", config.systolic_row, config.systolic_col);
    printf("IFMAP Buffer (KB): %d\n", config.ifmap_buffer);
    printf("Weight Buffer (KB): %d\n", config.weight_buffer);
    printf("OFMAP Buffer (KB): %d\n", config.ofmap_buffer);
    printf("Off-Chip Hierarchy: %s\n", config.offchip_hierarchy);
    printf("Tier 1 Bandwidth (GB/s): %d\n", config.tier1_bandwidth);
    printf("Tier 1 Read Latency (ns): %d\n", config.tier1_read_latency);
    printf("Tier 1 Write Latency (ns): %d\n", config.tier1_write_latency);
    printf("Tier 1 Read Energy per Bit (pJ): %d\n", config.tier1_read_energy_perbit);
    printf("Tier 1 Write Energy per Bit (pJ): %d\n", config.tier1_write_energy_perbit);
    printf("Tier 1 Static Power (mW/GB): %d\n", config.tier1_static_power_perGB);
    printf("Tier 2 Bandwidth (GB/s): %d\n", config.tier2_bandwidth);
    printf("Tier 2 Read Latency (ns): %d\n", config.tier2_read_latency);
    printf("Tier 2 Write Latency (ns): %d\n", config.tier2_write_latency);
    printf("Tier 2 Read Energy per Bit (pJ): %d\n", config.tier2_read_energy_perbit);
    printf("Tier 2 Write Energy per Bit (pJ): %d\n", config.tier2_write_energy_perbit);
    printf("Tier 2 Static Power (mW/GB): %d\n", config.tier2_static_power_perGB);
    printf("Page Size (KB): %d\n", config.page_size);
    printf("TLB Entry: %d\n", config.TLB_entry);
    printf("TLB Hit Latency (cycles): %d\n", config.TLB_hit_latency);
    printf("TLB Miss Penalty (cycles): %d\n", config.TLB_miss_penalty);
    */
}