var table = [];
for(let i = 0; i < 8; i++)
{
    table.push(new Array(8).fill(0));
}
function putQueen(x,y)
{
    for(let i  = 0; i < 8; i++)
    {
        table[x][i]++;
        table[i][y]++;
        
        if(x+i < 8)
        {
            if(y+i < 8)
                {
                    table[x+i][y+i]++;
                }
            if(y-i >= 0)    
                {   
                    table[x+i][y-i]++;
                }
        }
        if(x-i >= 0)
        {
            if(y+i < 8)
                {
                    table[x-i][y+i]++;
                }
            if(y-i >= 0)    
                {
                    table[x-i][y-i]++;
                }
        }
    }
    table[x][y]+=100;
}
function takeQueen(x,y){
        for(let i  = 0; i < 8; i++)
    {
        table[x][i]--;
        table[i][y]--;
        
        if(x+i < 8)
        {
            if(y+i < 8)
                table[x+i][y+i]--;
            if(y-i >= 0)    
                table[x+i][y-i]--;
        }
        if(x-i >= 0)
        {
            if(y+i < 8)
                table[x-i][y+i]--;
            if(y-i >= 0)    
                table[x-i][y-i]--;
        }
    }
    table[x][y]-=100;
}
function printable()
{
    var arr = [];
    for(let i = 0; i < 8; i++)
    {
        arr.push(new Array(8).fill("♟️"));
    }
    for(let i = 0; i< 8; i++)
    {
        for(let j = 0; j< 8; j++)
        {
            if(table[i][j] > 0)
                arr[i][j] = "☠️";
            if(table[i][j] > 100)
                arr[i][j] = "👑";
            
        }   
        console.log(arr[i].join(" "));
    }
}
function isFill()
{
    for(let i = 0; i < 8; i++)
    {
        for(let j = 0; j < 8; j++)
        {
            if(table[i][j] == 0)
            {
                return false;
            }
        }       
    }
    return true;
}
function solve(level){
    
    if(level == 5)
    {
        if(isFill())
        {
            printable();
            return true;
        }
    }
    for(let i = 0; i < 8; i++)
        {            
            for(let j = 0; j < 8; j++)
            {
                if(table[i][j] == 0)
                {
                    putQueen(i,j);
                    if(solve(level+1))
                        return true;
                    removeQueen(i,j);
                }
            }
        }
    return false;
}
solve(0);
