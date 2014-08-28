function set_tran(tran)
    % tran.h (Settings)
    fileID = fopen('tran.h', 'w');
    fprintf(fileID, '#ifndef __TRAN_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define __TRAN_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define TRANN %d\r\n', size(tran, 1));
    fprintf(fileID, '#endif\r\n');
    type('seq.h');
    
    % tran.cpp (Data)
    fileID = fopen('tran.cpp', 'w');

    fprintf(fileID, 'int g_tran[TRANN][] = {\r\n');
    for mat = tran'
        fprintf(fileID, '  {');
        fprintf(fileID, '%d,',mat{1});
        fprintf(fileID, '},\r\n');
    end
    fprintf(fileID, '};\r\n');

    fprintf(fileID, 'int g_tranlen[TRANN] = {');
    for mat = tran'
        fprintf(fileID, '%d,',size(mat{1}, 2));
    end
    fprintf(fileID, '};\r\n');

    type('tran.cpp');
end