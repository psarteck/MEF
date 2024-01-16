clear all
close all

%% Domaine 1

%figure(1)
x = linspace(0,1,65);
y = linspace(0,1,65);
[X,Y] = meshgrid(x,y);
% tri = delaunay(X,Y);
% trimesh(tri,X,Y, 'k', 'linewidth',2)
% axis equal
% 
% xlabel(['X'], FontSize=22)
% ylabel(['Y'], FontSize=22)
% title('Maillage pour le domaine 1', FontSize=22)

u = @(X,Y, numex) 16*X.*Y.*(1-Y).*(1-X) * (numex == 1) +  sin(pi*X).*sin(pi*Y) * (numex == 2) ...
    + cos(pi*X).*cos(pi*Y) * (numex == 3) ;


for i = 1:3
    numex = i;
    figure(1+i)
    surf(X,Y,u(X,Y, numex))
    colorbar   
    view([0 90])
    shading flat
    axis equal
    xlabel(['X'], FontSize=22)
    ylabel(['Y'], FontSize=22)
    title(['Solution pour le problème ',num2str(i),' Domaine 1'], FontSize=22)
end

%% Domaine 2


% figure(5)
% 
% [X,Y] = meshgrid(x,y);
% tri = delaunay(X,Y);
% trimesh(tri,X,Y, 'k', 'linewidth',2)
% axis equal
% xlabel(['X'], FontSize=22)
% ylabel(['Y'], FontSize=22)
% title('Maillage pour le domaine 1', FontSize=22)
% 
% u = @(X,Y, numex) 16*X.*Y.*(1-Y).*(1-X) * (numex == 1) +  sin(pi*X).*sin(pi*Y) * (numex == 2) ...
%     + cos(pi*X).*cos(pi*Y) * (numex == 3) ;
% 
% 
% for i = 1:3
%     numex = i;
%     figure(5+i)
%     surf(X,Y,u(X,Y, numex))
%     colorbar   
%     view([0 90])
%     axis equal
%     shading flat
%     xlabel(['X'], FontSize=22)
%     ylabel(['Y'], FontSize=22)
%     title(['Solution pour le problème ',num2str(i),' Domaine 2'], FontSize=22)
%end


%% Solution calculée 
i=0;
for d = 1:2
    for p = 1:3
        name = "./DossierFin/FichiersResultats/solCalc4"+num2str(d)+num2str(p)+".txt";
        data = load(name);

        taille = sqrt(length(data(:,3)));
        U = reshape(data(:,3),taille,taille);
        
        figure(10+i)
        i=i+1;
        surf(X,Y,U)
        colorbar   
        view([0 90])
        axis equal
        shading flat
        xlabel(['X'], FontSize=22)
        ylabel(['Y'], FontSize=22)
        title(['Solution pour le problème ',num2str(p),' Domaine ', num2str(d)], FontSize=22)
    end
end


% U = reshape(data(:,3),65,65);
% figure(9)
% surf(X,Y,abs(U-u(X,Y,1)))
% colorbar   
% view([0 90])
% axis equal
% shading flat
% xlabel(['X'], FontSize=22)
% ylabel(['Y'], FontSize=22)
% title(['Erreur ',num2str(i),' Domaine 2'], FontSize=22)