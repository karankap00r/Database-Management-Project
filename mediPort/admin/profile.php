<?php session_start();
	include 'includes/db.php';
	if(isset($_SESSION['user']) && isset($_SESSION['password']) == true){
		$sel_sql = "SELECT * FROM admins WHERE email = '$_SESSION[user]' AND password = '$_SESSION[password]'";
		if($run_sql = mysqli_query($conn, $sel_sql)){
			while($rows = mysqli_fetch_assoc($run_sql)){
				$f_name = $rows['f_name'];
				$l_name = $rows['l_name'];
				$contact_no = $rows['contact_no'];
				$email = $rows['email'];
				
			}
		}
	} else {
		header('Location:../index.php');
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<title>Admin Panel</title>
		<link rel="stylesheet" href="../../bootstrap/css/bootstrap.css">
		<script src="../../js/jquery.js"></script>
		<script src="../../bootstrap/js/bootstrap.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/sidebar.php';?>
		<div class="col-lg-10">
			<div style="width:20px;height:20px;"></div>
			<!----- Profile Area ------>
			<div class="col-lg-12">
				<div class="panel panel-primary">
					<div class="panel-heading">
						<div class="col-md-3">
							<img src="../images/img1.jpg" width="100%" class="img-thumbnail">
						</div>
						<div class="col-md-7">
							<h3><u><?php echo $f_name.' '.$l_name; ?></u></h3>
							<p><i class="glyphicon glyphicon-phone"></i><?php echo $contact_no; ?></p>
							<p><i class="glyphicon glyphicon-envelope"></i> <?php echo $email; ?></p>
						</div>
						<div class="clearfix"></div>
					</div>
				</div>
			</div>
			
			
		</div>
		
		<footer></footer>
	</body>
</html>