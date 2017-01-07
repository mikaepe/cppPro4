%n = 50; m = 20; 

fID = fopen('outfile.bin');
n = fread(fID,1,'int');
m = fread(fID,1,'int');
A = fread(fID,[(n+1)*(m+1) 2],'double');
fclose(fID);
plot(A(:,1),A(:,2),'*');

X = vec2mat(A(:,1),m+1)';
Y = vec2mat(A(:,2),m+1)';
Z = sin(0.01*X.^2).*cos(0.1*X) + Y

surf(X,Y,Z);
