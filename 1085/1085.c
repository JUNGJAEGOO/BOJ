#include <stdio.h>
main(){
	int x,y,w,h;
	scanf("%d%d%d%d",&x,&y,&w,&h);
	x=x>w/2?w-x:x;
	y=y>h/2?h-y:y;
	printf("%d",x<y?x:y);
}