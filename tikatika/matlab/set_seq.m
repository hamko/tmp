function set_seq(seqs)
    % seq.h (Settings)
    fileID = fopen('seq.h', 'w');
    
    fprintf(fileID, '#ifndef __SEQ_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define __SEQ_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#include "settings.h"\r\n');
    fprintf(fileID, '#define DATA_NUM %d\r\n', size(seqs, 1));
    fprintf(fileID, 'extern void set_data(void);\r\n');
    fprintf(fileID, '#endif\r\n');

    type('seq.h');
    
    % seq.c (Data)
    fileID = fopen('seq.c', 'w');
    
    fprintf(fileID, '#include "data.h"\r\n');
    fprintf(fileID, '#include "seq.h"\r\n');
    fprintf(fileID, '#include "settings.h"\r\n');
    s = 0;
    for seq = seqs(:, 1)'
        l = 0;
        for mat = seq{1}'
            fprintf(fileID, 'long g_seq_s%dl%d[] = {', s, l);
            fprintf(fileID, '%d,',mat{1});
            fprintf(fileID, '};\r\n');
            l = l + 1;
        end
        s = s + 1;
    end
    
    fprintf(fileID, 'int g_seqlen[DATA_NUM][LED_NUM] = {\r\n');
    for seq = seqs(:, 1)'
        fprintf(fileID, '  {');
        for mat = seq{1}'
            fprintf(fileID, '%d,',size(mat{1}, 2));
        end
        fprintf(fileID, '},\r\n');
    end
    fprintf(fileID, '};\r\n');
    
    fprintf(fileID, 'long g_seqtime[DATA_NUM] = {');
    fprintf(fileID, '%d,', cell2mat(seqs(:, 2)));
    fprintf(fileID, '};\r\n');

    
    % setting function  
    fprintf(fileID, 'void set_data(void) {\r\n');
    s = 0;
    for seq = seqs(:, 1)'
        l = 0;
        for mat = seq{1}'
            fprintf(fileID, '  data[%d].seq[%d] = g_seq_s%dl%d;\r\n', s, l, s, l);
            l = l + 1;
        end
        s = s + 1;
    end
    fprintf(fileID, '  int s, x;');
    fprintf(fileID, '  for (s = 0; s < DATA_NUM; s++) {\r\n');
    fprintf(fileID, '    for (x = 0; x < LED_NUM; x++) {\r\n');
    fprintf(fileID, '      data[s].len [x] = g_seqlen[s][x];\r\n');
    fprintf(fileID, '      data[s].seqlen[x] = g_seqtime[s];\r\n');
    fprintf(fileID, '    }\r\n');
    fprintf(fileID, '  }\r\n');
    fprintf(fileID, '}\r\n');

    type('seq.c');
end