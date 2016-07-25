<?php include 'includes/db.php';
?>

<!DOCTYPE html>
<html>
	<head>
		<title>CMS System</title>
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
											<h3><center>About Us</center></h3>
										</div>
										<div class="panel-body col-md-12">
											<p class="panel-body">We are a tech start-up based out of New Delhi, with the aim of bridging the gap between our users and doctors across various medical fields. You can choose your region of convenience and medical department and our database will provide you with all the results matching your search. You can then choose the best doctor matching your requirements based on various parameters displayed, for instance, the doctors&apos; qualification, their years of experience, consultation fee, etc. The doctors in our database are genuine to the best of our knowledge, and any changes in their professional and personal data are regularly updated.</p>
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