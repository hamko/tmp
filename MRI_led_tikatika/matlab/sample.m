seqs = {}; % All sequences

% Set Seq 1
setting_index = 1;
seqlen = 1600; % [ms]
seq = { % [ms]
    [0,100]
    [100,200]
    [200,300]
    [300,400,1500,1600]
    [400,500]
    [500,600]
    [600,700]
    [700,800]
    [800,900]
    [900,1000]
    [1000,1100]
    [1100,1200]
    [1200,1300]
    [1300,1400]
    [1400,1500]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Seq 2
setting_index = 2;
seqlen = 150; % [ms]
seq = { % [ms]
    [0,10]
    [10,20]
    [20,30]
    [30,40]
    [40,50]
    [50,60]
    [60,70]
    [70,80]
    [80,90]
    [90,100]
    [100,110]
    [110,120]
    [120,130]
    [130,140]
    [140,150]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Seq 3
setting_index = 3;
seqlen = 150;
seq = {
    [0,10]
    [10,20]
    [20,30]
    [30,40]
    [40,50]
    [50,60]
    [60,70]
    [70,80]
    [80,90]
    [90,100]
    [100,110]
    [110,120]
    [120,130]
    [130,140]
    [140,150]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Seq 4
setting_index = 4;
seqlen = 150; % [ms]
seq = { % [ms]
    [0,10]
    [10,20]
    [20,30]
    [30,40]
    [40,50]
    [50,60]
    [60,70]
    [70,80]
    [80,90]
    [90,100]
    [100,110]
    [110,120]
    [120,130]
    [130,140]
    [140,150]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Seq 5
setting_index = 5;
seqlen = 150;
seq = {
    [0,10]
    [10,20]
    [20,30]
    [30,40]
    [40,50]
    [50,60]
    [60,70]
    [70,80]
    [80,90]
    [90,100]
    [100,110]
    [110,120]
    [120,130]
    [130,140]
    [140,150]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Seq 6
setting_index = 6;
seqlen = 150;
seq = {
    [0,10]
    [10,20]
    [20,30]
    [30,40]
    [40,50]
    [50,60]
    [60,70]
    [70,80]
    [80,90]
    [90,100]
    [100,110]
    [110,120]
    [120,130]
    [130,140]
    [140,150]
    };
seqs{setting_index, 1} = seq;
seqs{setting_index, 2} = seqlen;

% Set Transition matrix
% The order of seqs
tran = {[1,2,3,4];[0,1,0];[1,2,3,4];[0,1,0];[1,2,3,4];[0,1,0];};

mri_dt_nanosec = 1000000000;

set_seq(seqs);
set_tran(tran);
mri_dt(mri_dt_nanosec);
