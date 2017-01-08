%n = 50; m = 20; 

% The grid of the function 
fID = fopen('gridOut.bin');
n = fread(fID,1,'int');
m = fread(fID,1,'int');
A = fread(fID,[(n+1)*(m+1) 2],'double');
fclose(fID);
plot(A(:,1),A(:,2),'*');

X = vec2mat(A(:,1),m+1)';
Y = vec2mat(A(:,2),m+1)';
Z = sin(0.01*X.^2).*cos(0.1*X) + Y;

surf(X,Y,Z);
title('The function u')

% Grid function for Dx
fID = fopen('DxOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
Dx = fread(fID,[n1 m1],'double')';
fclose(fID);

figure()
surf(X,Y,Dx)
title('First derivative w.r.t x')

% Grid function for Dy
fID = fopen('DyOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
Dy = fread(fID,[n1 m1],'double')';
fclose(fID);

figure()
surf(X,Y,Dy)
title('First derivative w.r.t y')

% Grid function for DDx
fID = fopen('DDxOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
DDx = fread(fID,[n1 m1],'double')';
fclose(fID);

figure()
surf(X,Y,DDx)
title('Second derivative w.r.t x')

% Grid function for DDy
fID = fopen('DDyOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
DDy = fread(fID,[n1 m1],'double')';
fclose(fID);

figure()
surf(X,Y,DDy)
title('Second derivative w.r.t y')

% Grid function for Laplace operator
fID = fopen('laplaceOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
laplace = fread(fID,[n1 m1],'double')';
fclose(fID);

figure()
surf(X,Y,laplace)
title('Laplace operator')
