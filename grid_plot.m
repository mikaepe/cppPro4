%n = 50; m = 20; 

fID = fopen('outfile.bin');
n = fread(fID,1,'int');
m = fread(fID,1,'int');
A = fread(fID,[(n+1)*(m+1) 2],'double');
fclose(fID);
plot(A(:,1),A(:,2),'*');
