<?php include 'includes/db.php';
?>
<!DOCTYPE html>
<html>
	<head>
		<title>MyPracto</title>
		<link rel="stylesheet" href="../bootstrap/css/bootstrap.css">
		<script src="../bootstrap/js/bootstrap.js"></script>
		<script src="../js/jquery.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div class="container">
			<article class="row">
				<section class="col-lg-8">
					<?php
						echo 	'<div class="col-lg-12">
									<div class="panel-info">
										<div class="panel-heading">
											<h3><center>Meet the Team</center></h3>
										</div>
										<div class="panel-body col-md-7">
										<p class="panel-body"> Say Hi! to the team or drop us a mail :)</p>
											<ul class="panel-body">
												<li>
													Lehar Bhandari
													<ul class="panel-body">
														<p><i class="glyphicon glyphicon-envelope"></i> <a href="mailto:lehar.b21@gmail.com" subject="" target="_top">lehar.b21@gmail.com</a></p>
														<p><i class="glyphicon glyphicon-phone"></i> 9899417986</p>
													</ul>
												</li>
												<li>
													Karan Kapoor
													<ul class="panel-body">
														<p><i class="glyphicon glyphicon-envelope"></i> <a href="mailto:coffeewithkaran007@gmail.com" subject="" target="_top">coffeewithkaran007@gmail.com</a></p>
														<p><i class="glyphicon glyphicon-phone"></i> 9910095640</p>
													</ul>
												</li>
												<li>
													Kiran Ahari
													<ul class="panel-body">
														<p><i class="glyphicon glyphicon-envelope"></i> <a href="mailto:ahari.kiran@gmail.com" subject="" target="_top">ahari.kiran@gmail.com</a></p>
														<p><i class="glyphicon glyphicon-phone"></i> 9654088196</p>
													</ul>
												</li>
											</ul>
										</div>
										<div class="clearfix"></div>
									</div>
								</div>';
					?>
				</section>
				<?php include 'includes/sidebar.php';?>
			</article>
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>