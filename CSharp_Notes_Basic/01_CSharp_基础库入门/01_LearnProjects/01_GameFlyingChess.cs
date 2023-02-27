using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _01_CSharp_基础库入门
{
    public class _01_GameFlyingChess
    {

        public static int[] Maps = new int[100];
        public static int[] PlayerPos = new int[2];
        public static string[] PlayerNames = new string[2];

        public _01_GameFlyingChess()
        {
            InitialMap();
            GameMenuShow();
            PlayerLogin();
            Console.Clear();
            GameMenuShow();
            
            Console.WriteLine("{0}的士兵用A表示", PlayerNames[0]);
            Console.WriteLine("{0}的士兵用B表示", PlayerNames[1]);
            
            GameMapShow();

            Console.WriteLine("按任意键继续");
            Console.ReadKey();
            while (PlayerPos[0] < 99 && PlayerPos[1] < 99)
            {
                //Console.Clear();
                GameMapShow();
                Console.ReadKey(true);
            }
        }

        public static void InitialMap()
        {

            void _initMap(int[] arr, int value)
            {
                for (int i = 0; i < arr.Length; i++)
                {
                    Maps[arr[i]] = value;
                }
            }

            int[] luckyturn = { 6, 23, 40, 55, 69, 83 };  // 幸运轮盘◎
            int[] landMin = { 4, 13, 17, 33, 38, 50, 64, 80, 94 };  // 地雷★
            int[] pause = { 9, 27, 60, 93 };  // 暂停▲
            int[] timeTunnel = { 20, 25, 45, 63, 72, 88, 90 };  // 时空隧道卍

            _initMap(luckyturn, 1);
            _initMap(landMin, 2);
            _initMap(pause, 3);
            _initMap(timeTunnel, 4);
        }

        public static void GameMapShow()
        {
            void _drawMap(int index)
            {
                if (PlayerPos[0] == PlayerPos[1] && PlayerPos[0] == index)
                {
                    Console.Write("<>");
                }
                else if (PlayerPos[0] == index)
                {
                    Console.Write("Ａ");
                }
                else if (PlayerPos[1] == index)
                {
                    Console.Write("Ｂ");
                }
                else
                {
                    switch (Maps[index])
                    {
                        case 0:
                            Console.ForegroundColor = ConsoleColor.White;
                            Console.Write("□");
                            break;
                        case 1:
                            Console.ForegroundColor = ConsoleColor.Yellow;
                            Console.Write("◎");
                            break;
                        case 2:
                            Console.ForegroundColor = ConsoleColor.DarkBlue;
                            Console.Write("★");
                            break;
                        case 3:
                            Console.ForegroundColor = ConsoleColor.DarkRed;
                            Console.Write("▲");
                            break;
                        case 4:
                            Console.ForegroundColor = ConsoleColor.Cyan;
                            Console.Write("卍");
                            break;
                        default:
                            break;
                    }
                }
            }


            int index_map = 0;

            // 第一横行
            for (; index_map < 30; index_map++)
            {
                _drawMap(index_map);
            }

            // 第一竖行
            for (; index_map < 35; index_map++)
            {
                Console.WriteLine();
                for (int i = 0; i < 29; i++)
                {
                    Console.Write("  ");
                }
                _drawMap(index_map);
            }

            // 第二横行
            Console.WriteLine();
            for (index_map = 64; index_map >= 35; index_map--)
            {
                _drawMap(index_map);
            }

            // 第二竖行
            for (index_map = 65; index_map < 70; index_map++)
            {
                Console.WriteLine();
                _drawMap(index_map);
            }

            // 第三横行
            Console.WriteLine();
            for (; index_map < 100; index_map++)
            {
                _drawMap(index_map);
            }

            Console.WriteLine();
        }

        public static void GameMenuShow()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("**************************");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("**************************");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("***0222.NET基础班飞行棋***");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("**************************");
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("**************************");
            Console.ForegroundColor = ConsoleColor.White;
        }

        public static void PlayerLogin()
        {
            Console.WriteLine("请输入玩家A的姓名:");
            PlayerNames[0] = Console.ReadLine();
            while (PlayerNames[0] == "")
            {
                Console.WriteLine("请重新输入玩家A的姓名:");
                PlayerNames[0] = Console.ReadLine();
            }

            Console.WriteLine("请输入玩家B的姓名:");
            PlayerNames[1] = Console.ReadLine();
            while (PlayerNames[1] == "" || PlayerNames[1] == PlayerNames[0])
            {
                Console.WriteLine("请重新输入玩家B的姓名:");
                PlayerNames[1] = Console.ReadLine();
            }
        }

        public static void PlayerGame()
        {
            // 如果玩家踩到另一个玩家，被踩的玩家退6格
            // 地雷：退6格；时空隧道：进10格；幸运轮盘：1 交换位置，2 对方退6格；暂停：暂停一回合
        }
    }
}
