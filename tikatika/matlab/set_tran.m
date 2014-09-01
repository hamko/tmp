function set_tran(tran)
    % tran.h (Settings)
    fileID = fopen('tran.h', 'w');
    fprintf(fileID, '#ifndef __TRAN_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define __TRAN_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#include "settings.h"\r\n'); 
    fprintf(fileID, '#define TRAN_NUM %d\r\n', size(tran, 1));
    fprintf(fileID, 'extern void set_tran(void);\r\n');
    fprintf(fileID, '#endif\r\n');
    type('tran.h');
    
    % tran.cpp (Data)
    fileID = fopen('tran.c', 'w');

    fprintf(fileID, '#include "data.h"\r\n');
    fprintf(fileID, '#include "tran.h"\r\n');
    fprintf(fileID, '#include "settings.h"\r\n');
    i = 0;
    for mat = tran'
        fprintf(fileID, 'int g_tran%d[] = ', i);
        fprintf(fileID, '  {');
        fprintf(fileID, '%d,',mat{1});
        fprintf(fileID, '};\r\n');
        i = i + 1;
    end

    fprintf(fileID, 'int g_tranlen[TRAN_NUM] = {');
    for mat = tran'
        fprintf(fileID, '%d,',size(mat{1}, 2));
    end
    fprintf(fileID, '};\r\n');

    % setting function  
    i = 0;
    fprintf(fileID, 'void set_tran(void) {\r\n');
    for mat = tran'
        fprintf(fileID, '  tran[%d].tran = g_tran%d;\r\n', i, i);
        i = i + 1;
    end
    fprintf(fileID, '  int i;\r\n');
    fprintf(fileID, '  for (i = 0; i < TRAN_NUM; i++) \r\n');
    fprintf(fileID, '    tran[i].len = g_tranlen[i];\r\n');
    fprintf(fileID, '}\r\n');

    type('tran.c');
end