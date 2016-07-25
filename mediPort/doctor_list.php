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
		<title>MyPracto</title>
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
						//$sel_sql = "SELECT * FROM doctors WHERE s_id = '$_POST[speciality]' AND c_id='$_POST[city]' ORDER BY fees LIMIT $start_from,$per_page";
						$sel_sql = "SELECT * FROM doctors d JOIN speciality s JOIN city c ON d.speciality = s.s_name AND d.city = c.c_name WHERE s.s_id = '$_GET[speciality]' AND c.c_id='$_GET[city]' ORDER BY fees LIMIT $start_from,$per_page";
						$run_sql = mysqli_query($conn,$sel_sql);
						if(mysqli_num_rows($run_sql)==0)
						{
							echo '<div class="alert alert-danger">Sorry! No doctor found.</div>';
						}
						else {
						while($rows = mysqli_fetch_assoc($run_sql)){
							echo '
							<div class="panel panel-info">
								<div class="panel-heading">
									<h3> Dr. '.$rows['f_name'].' '.$rows['l_name'].'</h3>
								</div>
								<div class="panel-body">
									<div class="col-lg-4">
										<i class="glyphicon glyphicon-education"></i> <b>Qualification</b> : '.$rows['qualification'].'
									</div>
									<div class="col-lg-4">
										<i class="glyphicon glyphicon-usd"></i> <b>Consulation Fees (Rs.): </b>'.$rows['fees'].'
									</div>
									<div class="col-lg-4">
										<i class="glyphicon glyphicon-star"></i> <b>Years of experience : </b>'.$rows['years_of_exp'].'
									</div>
								</div>
								<div class="panel-body panel-right">
									<a href="doctor.php?doctor_id='.$rows['d_id'].'" target="_blank" class="btn pull-right btn-primary">Know More</a>
								</div>
							</div>
							';
						}
						}
					?>
				<div class="panel-body panel-right">
					<a href="index.php" class="btn pull-right btn-danger">Go Back</a>
				</div>
				</section>
				<?php include 'includes/sidebar.php';?>
				</article>
				<div class="text-center">
				<ul class="pagination">
				<?php
					$pagination_sql = "SELECT * FROM doctors d JOIN speciality s JOIN city c ON d.speciality = s.s_name AND d.city = c.c_name WHERE s.s_id = '$_GET[speciality]' AND c.c_id='$_GET[city]'";
					$run_pagination = mysqli_query($conn, $pagination_sql);

					$count = mysqli_num_rows($run_pagination);
					
					$total_pages = ceil($count/$per_page);
					
					for($i=1;$i<=$total_pages;$i++){
						echo '<li><a href="doctor_list.php?page='.$i.'&speciality='.$_GET['speciality'].'&city='.$_GET['city'].'">'.$i.'</a></li>';
					}
					
				?>			
				</ul>
			</div>
			
		</div>
		<div style="width:50px;height:50px;"></div>
		<?php include 'includes/footer.php';?>
	</body>
</html>