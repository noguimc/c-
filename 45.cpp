cin>>n>>k;
for(int i=0;i<n.size();i++){
    if(n[i]>='0'&&n[i]<='9'){
        ans=ans*k+n[i]-'0';

    }else{
        ans=ans*k+n[i]-'A'+10;

        
    }

}
cout<<ans<<endl;