function mri_dt(mri_dt)
    % mri_dt.h (Settings)
    fileID = fopen('mri_dt.h', 'w');
    fprintf(fileID, '#ifndef __MRI_DT_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define __MRI_DT_HPP_INCLUDED__\r\n');
    fprintf(fileID, '#define MRI_DT %dLL\r\n', mri_dt);
    fprintf(fileID, '#endif\r\n');
    type('mri_dt.h');
   
end