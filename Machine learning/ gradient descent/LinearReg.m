%Gradient desecent for Linear regression model 
%used for training theta(parameter)
%LinearReg train theta vector using training dataset
%X is matrix m rows i.e. number of training examples
% and n columns i.e. number of features.
%y is vector of size m, containing actual values from dataset

%Loading data 
data = load('filename.txt');
dim=size(data);
num_row=dim(1,1);
num_col=dim(1,2);

for i=1:(num_col-1)
  if(i==1)
    X=data(:,1);
  else
    X=[X , data(:,i)];
  end  
end;    

y=data(:,num_col);

%adding a biased term in X matrix
X=[ones(m,1) X];

%initialization of theta
theta=zeros(size(X,2),1);

%number of features
num_fea=size(X,2)

%numbers of training examples
m=length(y);

%Gradient desecent
for j=1: max_iter
  h=(X*theta-y);
  for i=1: num_fea
  theta(i)=theta(i)-(learning_rate*(X(:,i)'*h)/m);
  end
end
