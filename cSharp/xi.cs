            Console.WriteLine("请输入点号，并以(，)隔开");
            string Pnum = Console.ReadLine();
            string[] res = pnum.Split(',');
            int l = res.Length;
            Console.WriteLine("请输入已知点的高程");
            double H0=Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("请输入后续点之间的高差，并以(，)隔开");
            string h = Console.ReadLine();
            string[] a = h.Split(',');//将字符串h分割为数组a
            double[] b = new double[l];
            
            double fh = 0;
            for(int i=0; i<l; i++)
            { b[i]= Convert.ToDouble(a[i]); 
                fh=fh+b[i];
            }
            double v=fh/l;//高差改正数
            double[] H=new double[l];
            H[0]=Convert.ToDouble(H0);
            for(int i=0; i<l-1; i++)
            { H[i + 1] = H[i] + b[i]-v;}
            for (int i = 0; i < l; i++)
            {
                Console.WriteLine("{0}点的高程为{1}", res[i], H[i]);
            }
            Console.WriteLine("高差闭合差为{0}\n改正数为{1}",fh,v);
            Console.ReadKey();