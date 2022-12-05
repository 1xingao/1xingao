using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace cSharp
{
    public class ClassFor10
    {
        
    }
    class Point {
        private double X;
        private double y;
        private double hid;
        private string name;
        private bool flag ;// true 已知， false 未知

        public Point(){
            this.x = 0;
            this.y = 0;
            this.hid = 0;
            this.name = "";
            this.flag = false;
        }

        public Point(double x,double y)
        {
            this.x = x;
            this.y = y;
            this.hid = 0;
            this.name = "";
            this.flag = false;
        }
        public Point(double x,double y,string name)
        {
            this.x = x;
            this.y = y;
            this.hid = 0;
            this.name = name;
            this.flag = false;
        }
        public Point(double x,double y,string name,double hid,bool flag)
        {
            this.x = x;
            this.y = y;
            this.hid = hid;
            this.name = name;
            this.flag = flag;
        }
        ~Point(){}
    }
}