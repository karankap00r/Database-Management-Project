<?php session_start();
	include 'includes/db.php';
		$login_err = '';
	if(isset($_GET['login_error'])){
		if($_GET['login_error'] == 'empty'){
			$login_err = '<div class="alert alert-danger">User name or Password was empty!</div>';
		}elseif($_GET['login_error'] == 'wrong'){
			$login_err = '<div class="alert alert-danger">User name or Password was Wrong!</div>';
		}elseif($_GET['login_error'] == 'query_error'){
			$login_err = '<div class="alert alert-danger">There is somekind of Database Issue!</div>';
		}
	}
	
	$per_page = 5;
	if(isset($_GET['page'])){
		$page = $_GET['page'];
	} else{
		$page = 1;
	}
	$start_from = ($page-1) * $per_page;
?>

<!DOCTYPE html>
<html>
	<head>
		<title>My Practo</title>
		<link rel="stylesheet" href="../bootstrap/css/bootstrap.css">
		<script src="../bootstrap/js/bootstrap.js"></script>
		<script src="../js/jquery.js"></script>
	</head>
	<body>
		<?php include 'includes/header.php';?>
		<div class="container">
			<?php echo $login_err; ?>
			<article class="row">
				<section class="col-lg-8">
					<?php
						for($i=0;$i<10;$i++)
						{
							echo '<br>';
						}
					?>
					<form class="form-horizontal" action="doctor_list.php" role="form">
					<div class="form-group col-sm-4">
						<br>
						<select id="speciality" name="speciality" class="form-control" required>
							<option value="" selected>Select Speciality</option>
							<?php
								$sel_sql = "SELECT * FROM speciality ORDER BY s_name";
								$run_sql = mysqli_query($conn,$sel_sql);
								while($rows = mysqli_fetch_assoc($run_sql)){
									echo '<option value="'.$rows['s_id'].'">'.ucfirst($rows['s_name']).'</option>';
								}
							?>
						</select>
					</div>
					<div class="form-group col-sm-5">
						<br>
						<select id="city" name="city" class="form-control" required>
							<option value="" selected>Select City</option>
							<?php
								$sel_sql = "SELECT * FROM city ORDER BY c_name";
								$run_sql = mysqli_query($conn,$sel_sql);
								while($rows = mysqli_fetch_assoc($run_sql)){
									echo '<option value="'.$rows['c_id'].'">'.ucfirst($rows['c_name']).'</option>';
								}
							?>
						</select>
					</div>
					<div class="form-group">
						<label class="col-lg-4 control-label"></label>
						<div class="col-lg-4" align="right">
							<input type="submit" value="Search" name="submit" class="btn btn-block btn-lg btn-info navbar-btn">
						</div>
					</div>
					</form>
				</section>
				<?php include 'includes/sidebar.php';?>
			</article>
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>