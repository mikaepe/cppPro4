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

% -------------------------------------------------------
% dudx
% -------------------------------------------------------

% Grid function for Dx
fID = fopen('DxOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
Dx = fread(fID,[m1 n1],'double')';
fclose(fID);

figure
surf(X,Y,Dx')
title('D0x (implemented dudx)')

% True x derivative
ZDX = 0.02.*X.*cos(0.01*X.^2).*cos(0.1*X) - 0.1.*sin(0.01*X.^2).*sin(0.1*X);
figure
surf(X,Y,ZDX)
title('dudx (true)')

% Difference between our dx and true
figure()
diff = ZDX-Dx';
surf(X,Y,diff)
title('dudx - D0x (true - implemented)')


% -------------------------------------------------------
% dudy
% -------------------------------------------------------

% Grid function for Dy
fID = fopen('DyOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
Dy = fread(fID,[m1 n1],'double')';
fclose(fID);

figure()
surf(X,Y,Dy')
title('D0y (implemented dudy)')

% True y derivative
ZDY = ones(size(Dy'));
figure;
surf(X,Y,ZDY)
title('dudy (true)')

% Difference betw our dy and true
figure;
diff = ZDY-Dy';
surf(X,Y,diff);
title('dudy-D0y (true - implemented)')


% -------------------------------------------------------
% d2udx2
% -------------------------------------------------------

% Grid function for DDx
fID = fopen('DDxOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
DDx = fread(fID,[m1 n1],'double')';
fclose(fID);

figure()
surf(X,Y,DDx')
title('d2udx2 (implemented)')


% -------------------------------------------------------
% d2udy2
% -------------------------------------------------------

% Grid function for DDy
fID = fopen('DDyOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
DDy = fread(fID,[m1 n1],'double')';
fclose(fID);

figure()
surf(X,Y,DDy')
title('d2udy2 (implemented)')


% -------------------------------------------------------
% Laplace-operator
% -------------------------------------------------------

% Grid function for Laplace operator
fID = fopen('laplaceOut.bin');
n1 = fread(fID,1,'int');
m1 = fread(fID,1,'int');
laplace = fread(fID,[m1 n1],'double')';
fclose(fID);

figure()
surf(X,Y,laplace')
title('Laplace operator')

