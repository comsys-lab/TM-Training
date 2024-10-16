struct TOPOLOGY {
    char layer[100];
    int ifmap_row;
    int ifmap_col;
    int filter_row;
    int filter_col;
    int channel;
    int num_filter;
    int stride;
};

//ifmap_row = ifmap height
//ifmap_col = ifmap width