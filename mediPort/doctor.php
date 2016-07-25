<?php include 'includes/db.php';
$error='';
	if(isset($_GET['doctor_id'])){
		$sel_sql = "SELECT * FROM doctors WHERE d_id = '$_GET[doctor_id]'";
		$run_sql = mysqli_query($conn,$sel_sql);
		while($rows = mysqli_fetch_assoc($run_sql)){
			$dname = 'Dr. '.$rows['f_name'].' '.$rows['l_name'];
			$qual=$rows['qualification'];
			$speciality=$rows['speciality'];
			$gender=$rows['gender'];
			$fees='Rs. '.$rows['fees'];
			$clinic_address=$rows['clinic_address'];
			$contact_no=$rows['contact_no'];
			$alt_contact_no=$rows['alt_contact_no'];
			$email=$rows['email'];
			$years_of_exp=$rows['years_of_exp'];
			$timings=$rows['timings'];
			
		}
	} else {
		
		$error= '<div class="alert alert-danger">No Post You&apos;ve selected to Show!<a href="index.php">Click Here</a> to Select a Post</div>';
	}
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
						if(isset($_GET['doctor_id'])){
						echo 	'<div class="col-lg-12">
									<div class="panel-info">
										<div class="panel-heading">
											<h3><u>'.$dname.'</u></h3>
										</div>
										<div class="panel-body col-md-7">
											<p><i class="glyphicon glyphicon-education"></i> <b>Qualification</b> : '.$qual.'</p>
											<p><i class="glyphicon glyphicon-bookmark"></i> <b>Speciality : </b>'.ucfirst($speciality).'</p>
											<p><i class="glyphicon glyphicon-phone"></i> <b>Contact number : </b>'.$contact_no.'</p>
											<p><i class="glyphicon glyphicon-phone-alt"></i> <b>Alternate contact number : </b>'.$alt_contact_no.'</p>
											<p><i class="glyphicon glyphicon-envelope"></i> <b>Email id : </b>'.$email.'</p>
											<p><i class="glyphicon glyphicon-user"></i> <b>Gender : </b>'.ucfirst($gender).'</p>
											<p><i class="glyphicon glyphicon-usd"></i> <b> Consultation Fees : </b>'.$fees.'</p>
											<p><i class="glyphicon glyphicon-home"></i> <b>Clinic address : </b>'.ucfirst($clinic_address).'</p>
											<p><i class="glyphicon glyphicon-time"></i> <b>Clinic timings : </b>'.$timings.'</p>
											<p><i class="glyphicon glyphicon-star"></i> <b>Years of experience : </b>'.$years_of_exp.'</p>
										</div>
										<div class="clearfix"></div>
									</div>
								</div>';
					} else {
						 echo $error; 
					}
					?>
				</section>
				<?php include 'includes/sidebar.php';?>
			</article>
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>