//18电信2 杨利纯 18100502203 
#include <stdio.h>
#include <string.h>
void ConfirmEdgeBlockColor(MagicCube up[][4],MagicCube down[][4],MagicCube left[][4],
              MagicCube right[][4],MagicCube front[][4],MagicCube back[][4],
           UINT Surface,int x,int y,int z,UINT *pColor)
{
 //根据坐标位置和已知棱块的一面颜色值确定其相邻面的颜色值
 int i,j;
 for (i=1;i<=3;i++)
 {
  for (j=1;j<=3;j++)
  {
   if (up[i][j].x==x&&up[i][j].y==y&&up[i][j].z==z&&Surface!=1)
   {
    *pColor=up[i][j].color;
   }
   else if (down[i][j].x==x&&down[i][j].y==y&&down[i][j].z==z&&Surface!=4)
   {
    *pColor=down[i][j].color;
   }
   else if (left[i][j].x==x&&left[i][j].y==y&&left[i][j].z==z&&Surface!=6)
   {
    *pColor=left[i][j].color;
   }
   else if (right[i][j].x==x&&right[i][j].y==y&&right[i][j].z==z&&Surface!=5)
   {
    *pColor=right[i][j].color;
   }
   else if (front[i][j].x==x&&front[i][j].y==y&&front[i][j].z==z&&Surface!=3)
   {
    *pColor=front[i][j].color;
   }
   else if (back[i][j].x==x&&back[i][j].y==y&&back[i][j].z==z&&Surface!=2)
   {
    *pColor=back[i][j].color;
   }
  }
 }
}
void SearchEdgeDstPosition(MagicCube *pDstMagic,UINT Surface,UINT color)
{
 //根据棱块指定的颜色和其所在的面寻找到其要旋转的目标位置
    if (Surface==1)
 {
  pDstMagic->y=1;
  if (color==yellow)
  {
   pDstMagic->x=0;
   pDstMagic->z=1;
  }
  else if (color==red)
  {
   pDstMagic->x=1;
     pDstMagic->z=0;
  }
  else if (color==orange)
  {
   pDstMagic->x=-1;
   pDstMagic->z=0;
  }
  else if (color==white)
  {
   pDstMagic->x=0;
   pDstMagic->z=-1;
  }
    }

 else if (Surface==2)
 {
  pDstMagic->z=-1;
  if (color==blue)
  {
   pDstMagic->x=0;
   pDstMagic->y=1;
  }
  else if (color==red)
  {
   pDstMagic->x=1;
     pDstMagic->y=0;
  }
  else if (color==orange)
  {
   pDstMagic->x=-1;
   pDstMagic->y=0;
  }
  else if (color==green)
  {
   pDstMagic->x=0;
   pDstMagic->y=-1;
  }
    }

 else if (Surface==3)
 {
  pDstMagic->z=1;
  if (color==blue)
  {
   pDstMagic->x=0;
   pDstMagic->y=1;
  }
  else if (color==red)
  {
   pDstMagic->x=1;
     pDstMagic->y=0;
  }
  else if (color==orange)
  {
   pDstMagic->x=-1;
   pDstMagic->y=0;
  }
  else if (color==green)
  {
   pDstMagic->x=0;
   pDstMagic->y=-1;
  }
    }

 else if (Surface==4)
 {
  pDstMagic->y=-1;
  if (color==yellow)
  {
   pDstMagic->x=0;
   pDstMagic->z=1;
  }
  else if (color==red)
  {
   pDstMagic->x=1;
     pDstMagic->z=0;
  }
  else if (color==orange)
  {
   pDstMagic->x=-1;
   pDstMagic->z=0;
  }
  else if (color==white)
  {
   pDstMagic->x=0;
   pDstMagic->z=-1;
  }
    }

 else if (Surface==5)
 {
  pDstMagic->x=1;
  if (color==yellow)
  {
   pDstMagic->y=0;
   pDstMagic->z=1;
  }
  else if (color==blue)
  {
   pDstMagic->y=1;
     pDstMagic->z=0;
  }
  else if (color==green)
  {
   pDstMagic->y=-1;
   pDstMagic->z=0;
  }
  else if (color==white)
  {
   pDstMagic->y=0;
   pDstMagic->z=-1;
  }
    }

 else if (Surface==6)
 {
  pDstMagic->x=-1;
  if (color==yellow)
  {
   pDstMagic->y=0;
   pDstMagic->z=1;
  }
  else if (color==blue)
  {
   pDstMagic->y=1;
     pDstMagic->z=0;
  }
  else if (color==green)
  {
   pDstMagic->y=-1;
   pDstMagic->z=0;
  }
  else if (color==white)
  {
   pDstMagic->y=0;
   pDstMagic->z=-1;
  }
    }
   else
   {
   pDstMagic->x=0;
   pDstMagic->y=0;
   pDstMagic->z=0;
   }
}
void ConfirmEdgeBlockSrcPosition(MagicCube up[][4],MagicCube down[][4],MagicCube left[][4],
                    MagicCube right[][4],MagicCube front[][4],MagicCube back[][4],
              UINT surface,int low,int col,int *pX,int *pY,int *pZ)
{
 //根据目标棱块所在的面确定其空间位置
 if (surface==1)
 {
  *pX=up[low][col].x;
  *pY=up[low][col].y;
  *pZ=up[low][col].z;
 }
 else if (surface==2)
 {
  *pX=back[low][col].x;
  *pY=back[low][col].y;
  *pZ=back[low][col].z;
 }
 else if (surface==3)
 {
  *pX=front[low][col].x;
  *pY=front[low][col].y;
  *pZ=front[low][col].z;
 }
 else if (surface==4)
 {
  *pX=down[low][col].x;
  *pY=down[low][col].y;
  *pZ=down[low][col].z;
 }
    else if (surface==5)
 {
  *pX=right[low][col].x;
  *pY=right[low][col].y;
  *pZ=right[low][col].z;
 }
 else if (surface==6)
 {
  *pX=left[low][col].x;
  *pY=left[low][col].y;
  *pZ=left[low][col].z;
 }
}
void TransformEdgeBlock(UINT surface,UINT *pDstSurface,int low,int col)
{
  //如果要旋转的棱块的侧面颜色和中心颜色同色，且棱块位于底面，则先将其调整至侧面位置
   if (low==3&&col==2)
   {
    if (surface==2)
    {
    chBuf[num++].ch="B0";
    *pDstSurface=5;
    }
    else if (surface==3)
    {
    chBuf[num++].ch="F0";
    *pDstSurface=6;
    }
    else if (surface==6)
    {
    chBuf[num++].ch="L0";
    *pDstSurface=2;
    }
      else if (surface==5)
    {
    chBuf[num++].ch="R0";
    *pDstSurface=3;
    }
   }
}
int IsSame(MagicCube up[][4],MagicCube down[][4],MagicCube left[][4],
    MagicCube right[][4],MagicCube front[][4],MagicCube back[][4],
    UINT surface)
{
 //判断要旋转的侧面的顶面棱块是否已旋转好
 if (surface==5)
 {
  if (up[2][3].color==blue&&right[1][2].color==red)
  {
   return 1;
  }
  else
  {
   return 0;
  } 
 }
 else if (surface==2)
 {
  if (up[1][2].color==blue&&back[1][2].color==white)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
 else if (surface==3)
 {
  if (up[3][2].color==blue&&front[1][2].color==yellow)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
 else if (surface==6)
 {
  if (up[2][1].color==blue&&left[1][2].color==orange)
  {
   return 1;
  }
  else
  {
   return 0;
  }
 }
 else
 {
  return 0;
 }
}
