function set_seq(seqs)
    % seq.h (Settings)
    fileID = fopen('seq.h', 'w');
    
    fprintf(fileID, '#ifndef __SEQ_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define __SEQ_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define SEQN %d\r\n', size(seqs, 1));
    fprintf(fileID, '#define LEDN %d\r\n', size(seqs{1, 1}, 1));
    fprintf(fileID, '#endif\r\n');

    type('seq.h');
    
    % seq.cpp (Data)
    fileID = fopen('seq.cpp', 'w');
    
    fprintf(fileID, 'long g_seq[SEQN][LEDN][] = {\r\n');
    for seq = seqs(:, 1)'
        fprintf(fileID, '  {');
        for mat = seq{1}'
            fprintf(fileID, '{');
            fprintf(fileID, '%d,',mat{1});
            fprintf(fileID, '},');
        end
        fprintf(fileID, '},\r\n');
    end
    fprintf(fileID, '};\r\n');
    
    fprintf(fileID, 'int g_seqlen[SEQN][LEDN] = {\r\n');
    for seq = seqs(:, 1)'
        fprintf(fileID, '  {');
        for mat = seq{1}'
            fprintf(fileID, '%d,',size(mat{1}, 2));
        end
        fprintf(fileID, '},\r\n');
    end
    fprintf(fileID, '};\r\n');
    
    fprintf(fileID, 'long g_seqlen[SEQN] = {');
    fprintf(fileID, '%d,', cell2mat(seqs(:, 2)));
    fprintf(fileID, '};\r\n');

    type('seq.cpp');
end