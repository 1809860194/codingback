<!DOCTYPE html>
<html>
 <head>
	<!--������ǰҳ��ı��뼯��charset=gbk,gb2312(���ı���)��utf-8���ʱ���-->
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <!--��ǰҳ�����Ҫ��-->
    <title>css3����</title>
		
    <meta name="author" content="P+��ʦ" />

    <!--css,js-->
    <style type="text/css">
		*{margin:0;padding:0;}
		html,body{
			height:100%;
		}
		body{
			background:radial-gradient(ellipse at center,#34679a 0%, #214163 50%, #0d1926 100%);/*���򽥱�   ��Բ*/
		}
		body > div{
			width:200px;/*��� px����  cm*/
			height:200px;/*�߶�*/
			border:1px #fff solid;/*�߿� ��� ��� ��ɫ*/
			border-radius:50%;/*Բ��*/
			position:absolute;
			top:15%;
			left:50%;
			margin-left:-101px;
			transform:rotateX(80deg) rotateY(20deg);
			transform-style:preserve-3d;
		}
		body > div:nth-of-type(2){
			transform:rotateX(-80deg) rotateY(20deg);
		}
		body > div:nth-of-type(3){
			transform:rotateX(-70deg) rotateY(60deg);
		}
		body > div:nth-of-type(4){
			transform:rotateX(70deg) rotateY(60deg);
		}
		body > div:first-of-type:after{
			width:40px;
			height:40px;
			content:"";
			background:#fff;
			position:absolute;
			top:50%;
			left:50%;
			margin-top:-20px;
			margin-left:-20px;
			transform:rotateX(80deg);
			border-radius:50%;
			animation:nucleus 2s infinite linear;
		}
		body > div > div{
			width:200px;
			height:200px;
			position:relative;
			transform-style:preserve-3d;
			animation:trail 1s infinite linear; /*�Զ��嶯��  �������� ʱ�� ���Ŵ��� �ٶ�*/
		}
		body > div > div:after{
			content:"";
			width:5px;
			height:5px;
			background:#fff;
			position:absolute;
			top:-5px;
			left:50%;
			margin-left:-5px;
			border-radius:50%;
			box-shadow:0 0 12px #fff;/*��Ӱ x y ģ���� ��ɫ*/
			animation:particle 1s infinite linear;
		}
		/*�Զ��嶯��ִ��*/
		@keyframes trail{
			from{
				transform:rotateZ(0deg);
			}
			to{
				transform:rotateZ(360deg);
			}
		}
		@keyframes particle{
			from{
				transform:rotateX(90deg) rotateY(0deg);
			}
			to{
				transform:rotateX(90deg) rotateY(-360deg);
			}
		}
		@keyframes nucleus{
			0%{
				box-shadow:0 0 0 transparent;
			}
			50%{
				box-shadow:0 0 25px #fff;
			}
			100%{
				box-shadow:0 0 0 transparent;
			}
		}
		body > div:nth-of-type(2) > div,
		body > div:nth-of-type(2) > div:after{
			animation-delay:-0.5s;
		}
		body > div:nth-of-type(3) > div,
		body > div:nth-of-type(3) > div:after{
			animation-delay:-1s;
		}
		body > div:nth-of-type(4) > div,
		body > div:nth-of-type(4) > div:after{
			animation-delay:-1.5s;
		}

   </style>
 </head>
 <body>
	<div><div></div></div>
	<div><div></div></div>
	<div><div></div></div>
	<div><div></div></div>
 </body>
</html>