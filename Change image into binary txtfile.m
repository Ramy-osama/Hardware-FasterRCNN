    img = dec2bin(rgb2gray(imread('230464575.jpg')));
    fid = fopen('test_binary_file.txt','w');
    fprintf(fid,'%c%c%c%c%c%c%c%c\r\n',img');
    fclose(fid);